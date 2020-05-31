
double dot(lc a, lc b) {
    return (a * conj(b)).real();
}
double cross(lc a, lc b) {
    return (a * conj(b)).imag();
}

template<typename T>
struct Convex {
    using P = complex<T>;
    ll n;
    vector<ll> conv;
    vector<P> v;

    T cross(P a, P b) {
        return (a * conj(b)).imag();
    }

    Convex(const vector<P> &_v) {
        // incremental method
        n = _v.size();
        v = _v;

        sort(v.begin(), v.end(),
                [&](P a, P b) {
                return real(a) == real(b) ? imag(a) < imag(b) : real(a) < real(b);
                });

        P mp = v[0], Mp = v[n-1];

        vector<ll> up, dn;
        for(ll i=0; i<n; i++) {
            P p = v[i];
            if(cross(Mp - mp, p - mp) <= 0) {
                // up
                while(up.size()>=2 && cross(p - v[up[up.size()-1]], v[up[up.size()-2]] - v[up[up.size()-1]]) < 0)
                    up.pop_back();
                up.push_back(i);
            }
            if(cross(Mp - mp, p - mp) >= 0) {
                // dn
                while(dn.size()>=2 && cross(p - v[dn[dn.size()-1]], v[dn[dn.size()-2]] - v[dn[dn.size()-1]]) > 0)
                    dn.pop_back();
                dn.push_back(i);
            }
        }
        reverse(up.begin(), up.end());
        conv = up;
        conv.insert(conv.end(), dn.begin()+1, dn.end()-1);
    }

    P operator[](ll i) {
        return v[conv[i]];
    }
    ll size() {
        return conv.size();
    }

    double diam() {
        ll i = 0, j;
        j = find(conv.begin(), conv.end(), n-1) - conv.begin();
        T res = norm((*this)[i] - (*this)[j]);
        for(ll k=0; k<10*n; k++) {
            if(cross((*this)[(i+1)%size()] - (*this)[i], (*this)[(j+1)%size()] - (*this)[j]) >= 0)
                j = (j+1) % size();
            else
                i = (i+1) % size();
            res = max(res, norm((*this)[i] - (*this)[j]));
        }
        return sqrt(res);
    }
};
