if (n & 1) {
	cout << "No";
	return 0;
}
for (int i = 0; i < n / 2; ++i) {
	if (x[0] + x[n / 2] != x[i] + x[i + n / 2] || y[0] + y[n / 2] != y[i] + y[i + n / 2]) {
		cout << "No";
		return 0;
	}
}