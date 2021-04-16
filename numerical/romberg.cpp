K romberg(K l, K r, int n) {
	auto trapezoid = [l, r](int n) {
		K h = (r - l) / n;
		K sum = - (f(l) + f(r)) / 2;
		FOR(i, 0, n + 1) sum += f(l + i * h);
		return sum * h;
	};
	vector<K> rom(n);
	FOR(i, 0, n) rom[i] = trapezoid(1 << i);
	FOR(j, 1, n) FOR(i, 0, n - j) rom[i] = ((1ll << j * 2) * rom[i + 1] - rom[i]) / ((1ll << j * 2) - 1);
	return rom[0];
}
