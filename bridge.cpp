
{
    vector<long> idx(n, -1), l(n);
    long r = 0;
    {
        auto dfs = [&](auto dfs, long cur, long pre, long &x) -> void {
            l[cur] = idx[cur] = x++;
            for(auto &v: G[cur]) {
                if(v == pre) continue;
                if(idx[v] == -1)
                    dfs(dfs, v, cur, x);
                l[cur] = min(l[cur], l[v]);

                if(idx[cur] < l[v])
                    r++; // bridge
            }
        };

        long x = 0;
        dfs(dfs, 0, -1, x);
    }
}
