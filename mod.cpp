{
    auto modinv = [&](ll a, ll b) {
        ll u = 1, v = 0;
        while (b) {
            long long t = a / b;
            a -= t * b, swap(a, b);
            u -= t * v, swap(u, v);
        }
        return ((u % b) + b) % b;
    };

    auto mod(a, b) {
        return ((a%b)+b)%b;
    };
}
