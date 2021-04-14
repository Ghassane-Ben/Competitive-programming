vector<pair<int, int>> factorize(int n)
{
	int count = 0;
	vector<pair<int, int>>ans;

	// count the number of times 2 divides
	while (!(n % 2)) {
		n >>= 1; // equivalent to n=n/2;
		count++;
	}

	// if 2 divides it
	if (count)
		ans.push_back({2, count});

	// check for all the possible numbers that can
	// divide it
	for (int i = 3; i <= sqrt(n); i += 2) {
		count = 0;
		while (n % i == 0) {
			count++;
			n = n / i;
		}
		if (count)
			ans.push_back({i, count});
	}

	// if n at the end is a prime number.
	if (n > 2)
		ans.push_back({n, 1});

	return ans;
}