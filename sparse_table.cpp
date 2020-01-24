template<typename T>
struct SparseTable {
    using F = function<T(T,T)>;

    F f;
    vector<vector<T>> st;
    
    SparseTable(const vector<T> &v, const F &f_) : f(f_) {
        size_t b = 0;
        while(((size_t)1 << b) <= v.size()) b++;
        st.assign(b, vector<T>(1<<b));
        copy_n(v.begin(), v.size(), st[0].begin());

        for(size_t i=1; i<b; i++)
            for(int j=0; j+(1<<(i-1)) + (1<<(i-1)) < (1<<b); j++)
                st[i][j] = f(st[i-1][j], st[i-1][j + (1<<(i-1))]);
    }

    // [l, r)
    inline T query(size_t l, size_t r) const {
        size_t b = 0;

        while(((size_t)1 << b) <= (r - l)) b++;
        b--;

        return f(st[b][l], st[b][r - (1<<b)]);
    }
};

// SparseTable<long> st(a, [&](long a, long b){return min(a, b);});
