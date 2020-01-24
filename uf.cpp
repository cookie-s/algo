class UF {
public:
    vector<int> p;
    UF(size_t n) : p(n) {
        for(size_t i=0; i<n; i++)
            p[i] = i;
    };
    int find(int x) {
        if(p[x] == x) return x;
        return p[x] = find(p[x]);
    };
    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        p[x] = y;
    };
};

