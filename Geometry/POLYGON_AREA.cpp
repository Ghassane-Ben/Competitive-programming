#define int long long
struct Point {
	int x, y;
	void read() {
		cin >> x >> y;
	}
	Point operator - (Point b) {
		return Point{x - b.x, y - b.y};
	}
	void operator -=(Point b) {
		x = x - b.x;
		y = y - b.y;
	}
	int operator *(Point b) {
		return x * b.y - y * b.x;
	}
};
int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<Point>points(n);
	for (int i = 0; i < n; i++) {
		points[i].read();
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			ans += (points[i] * points[n - 1]);
		}
		else {
			ans += (points[i] * points[i - 1]);
		}
	}
	cout << abs(ans) << endl;
 
 
 
}