int moduloMultiplication(int a, int b)
{
	int res = 0;
	a %= mod;

	while (b > 0) {
		// If b is odd, add a with result
		if (b & 1)
			res = (res + a) % mod;

		a = (2 * a) % mod;

		b >>= 1;
	}

	return res;
}