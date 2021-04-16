ll binaryGCD(ll a, ll b) {
    if(a == 0) return b;
    int shift = __builtin_ctzll(a | b);
    a >>= __builtin_ctzll(a);
    while(b) {
        b >>= __builtin_ctzll(b);
        if(a > b) swap(a, b);
        b -= a;
    }
    return a << shift;
}
