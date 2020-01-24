struct RollingHash {
    using I = long long;
    static constexpr size_t L = 2;
    static constexpr I bs[L] = {1007, 2009};
    static constexpr I ms[L] = {1000000007, 1000000009};

    using T = pair<I, I>;

    vector<I> hs[L], pws[L];

    RollingHash(const string &s) {
        size_t n = s.size();
        for(size_t i=0; i<L; i++) {
            hs[i].assign(n+1, 0);
            pws[i].assign(n+1, 0);
            pws[i][0] = 1;
            for(size_t j=0; j<n; j++) {
                pws[i][j+1] = (pws[i][j]*bs[i]) % ms[i];
                hs[i][j+1] = (hs[i][j]*bs[i] + s[j]) % ms[i];
            }
        }
    }

    // [l, r)
    inline T hash(size_t l, size_t r) const {
        return {
            (((hs[0][r] - hs[0][l] * pws[0][r-l]) % ms[0]) + ms[0]) % ms[0],
            (((hs[1][r] - hs[1][l] * pws[1][r-l]) % ms[1]) + ms[1]) % ms[1],
        };
    }
};
// for <= C++14
constexpr RollingHash::I RollingHash::bs[];
constexpr RollingHash::I RollingHash::ms[];
