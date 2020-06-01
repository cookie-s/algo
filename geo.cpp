
double dot(lc a, lc b) {
    return (a * conj(b)).real();
}
double cross(lc a, lc b) {
    return (a * conj(b)).imag();
}

template<typename T>
struct Convex {
    using P = complex<T>;
    vector<ll> conv;
    vector<P> v;

    T cross(P a, P b) {
        return (a * conj(b)).imag();
    }

    Convex(const vector<P> &_v) {
        // incremental method
        ll n = _v.size();
        v = _v;

        auto comp = [&](P a, P b) {
            return make_tuple(real(a),imag(a)) < make_tuple(real(b), imag(b));
        };
        sort(v.begin(), v.end(), comp);

        ll k = 0;
        conv.resize(n+1);
        for(ll i=n-1; i>=0; conv[k++] = i--) // up
            while(k>=2 && cross(v[i] - v[conv[k-1]], v[conv[k-2]] - v[conv[k-1]]) > 0) k--;
        for(ll i=1, t=k+1; i<n; conv[k++] = i++) // dn
            while(k>=t && cross(v[i] - v[conv[k-1]], v[conv[k-2]] - v[conv[k-1]]) > 0) k--;
        conv.resize(k-1);
    }

    P operator[](ll i) {
        return v[conv[i]];
    }
    ll size() {
        return conv.size();
    }

    double diam() {
        ll i=0, j=0;
        for(ll k=0; k<size(); k++) {
            if(imag((*this)[i]) < imag((*this)[k])) i = k;
            if(imag((*this)[j]) > imag((*this)[k])) j = k;
        }
        ll si = i, sj = j;

        T res = 0;
        do {
            res = max(res, norm((*this)[i] - (*this)[j]));
            if(cross((*this)[(i+1)%size()] - (*this)[i], (*this)[(j+1)%size()] - (*this)[j]) <= 0)
                j = (j+1) % size();
            else
                i = (i+1) % size();
        } while(!(si == i && sj == j));
        return sqrt(res);
    }
};
