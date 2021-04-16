bool millerRabin(ll n, int iter = 5) {
	if(n < 4) return n > 1;
	int s = __builtin_ctzll(n - 1);
	ll d = (n - 1) >> s;
	auto composite = [n, d, s]() {
		ll x = binaryPow(rand() % (n - 3) + 2, d, n);
		if(x == 1 || x == n - 1) return 0;
		FOR(r, 1, s) {
			x = (__int128) x * x % n;
			if(x == n - 1) return 0;
		}
		return 1;
	};
	FOR(i, 0, iter) if(composite()) return 0;
    return 1;
}
