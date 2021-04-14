const int maxn = ;
const int mod = ;
long long fact[maxn], fin[maxn];
long long binpow(long long a, long long b) {

	long long res = 1;
	a = a % mod;
	while (b > 0) {
		if (b & 1)
			res = (res * a) % mod;

		a = (a * a) % mod;
		b >>= 1;
	}
	return res;
}
long long inverse(long long a) {
	return binpow(a, mod - 2);
}
void calcola() { //da chiamare all'inizio del programma ogni volta
	fact[0] = 1;
	for (int i = 1; i < maxn; i++)
		fact[i] = fact[i - 1] * i % mod;

	fin[maxn - 1] = inverse(fact[maxn - 1]);
	for (int i = maxn - 2; i >= 0; i--) {
		fin[i] = fin[i + 1] * (i + 1) % mod;
	}
}

long long nCr(long long n, long long r) {
	if (r < 0 || r > n)
		return 0;
	return ((fact[n] * fin[r]) % mod * fin[n - r]) % mod;
}





