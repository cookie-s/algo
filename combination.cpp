using ll = long long;

template<ll MOD = 1'000'000'007, ll MAX = 1'000'000>
struct Mod {
    vector<ll> fact, ifact;
    Mod() {
        fact.assign(MAX+1, 1);
        for(ll i=1; i<=MAX; i++)
            (fact[i] = i * fact[i-1]) %= MOD;

        ifact.assign(MAX+1, 1);
        {
            ll a = fact[MAX], b = MOD-2;
            while(b) {
                if(b&1) (ifact[MAX] *= a) %= MOD;
                (a *= a) %= MOD;
                b >>= 1;
            }
        }
        for(ll i=MAX-1; i>=0; i--)
            (ifact[i] = ifact[i+1] * (i+1)) %= MOD;
    }

    ll comb(ll a, ll b) {
        if(a < b) return 0;
        return ((fact[a] * ifact[b]) % MOD * ifact[a-b]) % MOD;
    }

}

