struct Prime {
    vector<char> nprime;
    Prime(size_t n) : nprime(n+1) {
        nprime[0] = nprime[1] = 1;
        for(size_t i=2; i<=n; i++) {
            if(nprime[i]) continue;
            for(size_t j=2; i*j<=n; j++)
                nprime[i*j] = 1;
        }
    };
    bool is(size_t i) {
        return nprime[i] == 0;
    };
};
