
int addition(int v1, int v2, int mod = MOD) {
	int res = v1 + v2;

	if (res < 0)
		res += mod;

	else if (res >= mod)
		res -= mod;
	return res;
}