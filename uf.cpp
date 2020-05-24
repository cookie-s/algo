class UF {
public:
    vector<int> p, sz;
    UF(size_t n) : p(n), sz(n) {
        for(size_t i=0; i<n; i++)
            p[i] = i, sz[i] = 1;
    };
    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    };
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) return;
        sz[y] += sz[x];
        p[x] = y;
    };
};

