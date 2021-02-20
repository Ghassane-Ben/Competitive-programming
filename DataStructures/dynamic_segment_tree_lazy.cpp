
struct node {
	int s, e;
	int mn, mx, sum;
	bool lset;
	int add_val, set_val;
	node *l, *r;

	node (int _s, int _e, int A[] = NULL): s(_s), e(_e), mn(0), mx(0), sum(0), lset(0), add_val(0), set_val(0), l(NULL), r(NULL) {
		if (A == NULL)
			return;
		if (s == e)
			mn = mx = sum = A[s];
		else {
			l = new node(s, (s + e) >> 1, A), r = new node((s + e + 2) >> 1, e, A);
			combine();
		}
	}
	void create_children() {
		if (s == e) return;
		if (l != NULL) return;
		int m = (s + e) >> 1;
		l = new node(s, m);
		r = new node(m + 1, e);
	}
	void self_set(int v) {
		lset = 1;
		mn = mx = set_val = v;
		sum = v * (e - s + 1);
		add_val = 0;
	}
	void self_add(int v) {
		if (lset) {
			self_set(v + set_val);
			return;
		}
		mn += v, mx += v, add_val += v;
		sum += v * (e - s + 1);
	}

	void lazy_propagate() {
		if (e == s)
			return;
		if (lset) {
			l->self_set(set_val), r->self_set(set_val);
			lset = set_val = 0;
		}
		if (add_val != 0) {
			l->self_add(add_val), r->self_add(add_val);
			add_val = 0;
		}
	}
	void combine() {
		if (l == NULL)
			return;
		sum = l->sum + r->sum;
		mn = min(l->mn, r->mn);
		mx = max(l->mx, r->mx);
	}

	void point_update(int pos, int val) {
		if (e == s) {
			mx = val;
		}
		else {
			int mid = (e + s) / 2;
			if (pos <= mid) {
				l->point_update(pos, val);
			}
			else {
				r->point_update(pos, val);
			}
			combine();
		}
	}
	void add(int x, int y, int v) {
		if (s == x && e == y) {
			self_add(v);
			return;
		}
		int m = (s + e) >> 1;
		create_children();
		lazy_propagate();
		if (x <= m)
			l->add(x, min(y, m), v);
		if (y > m)
			r->add(max(x, m + 1), y, v);
		combine();
	}

	void range_set(int x, int y, int v) {
		if (s == x && e == y) {
			self_set(v);
			return;
		}
		int m = (s + e) >> 1;
		create_children();
		lazy_propagate();
		if (x <= m)
			l->range_set(x, min(y, m), v);
		if (y > m)
			r->range_set(max(x, m + 1), y, v);
		combine();
	}
	int range_sum(int x, int y) {
		if (s == x && e == y)
			return sum;
		if (l == NULL || lset)
			return (sum / (e - s + 1)) * (y - x + 1);
		int m = (s + e) >> 1;
		lazy_propagate();
		if (y <= m)
			return l->range_sum(x, y);
		if (x > m)
			return r->range_sum(x, y);
		return l->range_sum(x, m) + r->range_sum(m + 1, y);
	}
	int range_min(int x, int y) {
		if (s == x && e == y)
			return mn;

		if (l == NULL || lset)
			return mn;

		int m = (s + e) >> 1;

		lazy_propagate();

		if (y <= m)
			return l->range_min(x, y);

		if (x > m)
			return r->range_min(x, y);

		return min(l->range_min(x, m), r->range_min(m + 1, y));
	}

	int range_max(int x, int y) {
		if (s == x && e == y)
			return mx;

		if (l == NULL || lset)
			return mx;

		int m = (s + e) >> 1;

		lazy_propagate();

		if (y <= m)
			return l->range_max(x, y);

		if (x > m) return
			    r->range_max(x, y);

		return max(l->range_max(x, m), r->range_max(m + 1, y));
	}

	int trova(int pos) {

		if (e == s) {
			return sum;
		}
		if (l == NULL || lset)
			return (sum / (e - s + 1));

		int m = (e + s) >> 1;

		lazy_propagate();

		if (pos <= m)
			return l->trova(pos);

		else return r->trova(pos);


	}

	~node() {
		if (l != NULL) delete l;
		if (r != NULL) delete r;
	}
};

