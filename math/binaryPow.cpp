ll binaryPow(ll base, ll exp, ll mod){
	ll ret = 1;
	while(exp){
		if(exp & 1) ret = (__int128) ret * base % mod;
		base = (__int128) base * base % mod;
		exp >>= 1;
	}
	return ret;
}
