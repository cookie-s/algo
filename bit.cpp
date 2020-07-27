
// https://qiita.com/drken/items/7c6ff2aa4d8fce1c9361
ll next_combination(ll sub) {
    ll x = sub & -sub, y = sub + x;
    return (((sub & ~y) / x) >> 1) | y;
}
