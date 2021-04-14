#define int long long
struct Point {
	int x, y;
	void read() {
		cin >> x >> y;
	}
	Point operator - (const Point b)const {
		return Point{x - b.x, y - b.y};
	}
	void operator -=(const Point& b) {
		x = x - b.x;
		y = y - b.y;
	}
	int operator *(const Point& b)const {
		return x * b.y - y * b.x;
	}
	bool operator <(const Point &b) const {
		return make_pair(x, y) < make_pair(b.x, b.y);
	}
	int triangle(const Point &b, const Point &c)const {
		return (b - *this) * (c - *this);
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
	sort(points.begin(), points.end());

	vector<Point>hull;
	for (int rep = 0; rep < 2; rep++) {
		int S = hull.size(); // for second iteration
		for (Point P : points) {

			while (hull.size() - S >= 2) {
				Point a = hull[hull.size() - 2];
				Point b = hull[hull.size() - 1];
				if (a.triangle(b, P) <= 0) { //if b on the left of P or collinear. Checking with cross product will
					//avoid bottom points
					break;
				}
				hull.pop_back();
			}
			hull.push_back(P);
		}
		hull.pop_back();//remove rightmost point
		reverse(points.begin(), points.end());
	}

	cout << hull.size() << '\n';
	for (Point p : hull) {
		cout << p.x << " " << p.y << '\n';
	}
}