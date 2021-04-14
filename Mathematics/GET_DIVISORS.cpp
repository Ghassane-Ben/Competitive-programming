vector<int>getDivisors(int n) {
	vector<int>v;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0 ) {
			if (n / i == i) {
				v.push_back(i);
			}
			else {
				v.push_back(i);
				v.push_back(n / i);
			}
		}
	}
	return v;
}