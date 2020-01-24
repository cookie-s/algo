struct LCA {
    vector<vector<long>> park;
    vector<long> h;
    long n, d;

    LCA(vector<long> &par) {
        // par[root] == -1
        n = par.size();
        h.assign(n, -1);
        {
            auto dfs = [&](auto dfs, long cur) -> long {
                if(par[cur] == -1) return h[cur] = 0;
                if(h[cur] != -1) return h[cur];
                return h[cur] = 1 + dfs(dfs, par[cur]);
            };
            for(long i=0; i<n; i++)
                dfs(dfs, i);
        }

        d=1;
        while(1L<<d < n) d++;

        park.assign(d, vector<long>(n));
        copy(par.begin(), par.end(), park[0].begin());

        for(long k=1; k<d; k++)
            for(long i=0; i<n; i++) {
                if(park[k-1][i] == -1) continue;
                park[k][i] = park[k-1][park[k-1][i]];
            }
    }

    long query(long u, long v) const {
        if(h[u] > h[v])
            swap(u, v);
        for(long i=d-1; i>=0; i--)
            if(h[v]-h[u] >= 1L<<i)
                v = park[i][v];

        if(v == u) return v;

        for(long i=d-1; i>=0; i--)
            if(park[i][v] != park[i][u])
                v = park[i][v], u = park[i][u];
        return park[0][v];
    }
};
