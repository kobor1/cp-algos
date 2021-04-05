ll rhoPollard(ll n){
	if((n & 1) ^ 1) return 2;
	ll x, y, g = 1, c = rand() % n + 1;
	x = y = rand() % n + 1;
	auto step = [n, c](ll x){
		return ((__int128) x * x + c) % n;
	};
	while(g == 1){
		x = step(x);
		y = step(step(y));
		g = binaryGCD(abs(x - y), n);
	}
	return g;
}

void factorize(ll num, vector<ll> &factors){
	if(num == 1) return;
	if(MillerRabin(num)) return factors.PB(num);
	ll divis = rhoPollard(num);
	factorize(divis, factors), factorize(num / divis, factors);
}
