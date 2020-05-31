struct LCA {
    vector<vector<ll>> park;
    vector<ll> h;
    ll n, d;

    LCA(vector<ll> &par) {
        // par[root] == root
        n = par.size();
        h.assign(n, -1);
        {
            auto dfs = [&](auto dfs, ll cur) -> ll {
                if(par[cur] == cur) return h[cur] = 0;
                if(h[cur] != -1) return h[cur];
                return h[cur] = 1 + dfs(dfs, par[cur]);
            };
            for(ll i=0; i<n; i++)
                dfs(dfs, i);
        }

        for(d=0; 1l<<d < n; d++);

        park.assign(d, vector<ll>(n));
        copy(par.begin(), par.end(), park[0].begin());

        for(ll k=1; k<d; k++)
            for(ll i=0; i<n; i++)
                park[k][i] = park[k-1][park[k-1][i]];
    }

    ll query(ll u, ll v) const {
        if(h[u] > h[v]) swap(u, v);

        for(ll i=0; i<d; i++)
            if((h[v]-h[u])>>i & 1)
                v = park[i][v];

        if(v == u) return v;

        for(ll i=d-1; i>=0; i--)
            if(park[i][v] != park[i][u])
                v = park[i][v], u = park[i][u];
        return park[0][v];
    }
};
