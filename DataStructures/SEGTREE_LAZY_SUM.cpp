//IN QUERY {L,R} RICORDA CHE R E' AUMENTATO DI 1, CIOE SUM (1,3) DEVE ESSERE SCRITTO COME SUM(1,4)

struct segtree {
	struct node {
		int sum;
		int setVal;
		bool toSet;
	};
	vector<node>tree;
	int size;
	void build(vector<int>&a, int x, int lx, int rx) {
		if (rx - lx == 1) {
			if (lx < a.size()) {
				tree[x].sum = a[lx];
			}
		}
		else {
			int mid = (lx + rx) / 2;
			build(a, 2 * x + 1, lx, mid);
			build(a, 2 * x + 2, mid, rx);
			tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
		}
	}
	segtree(vector<int>&a, int n) {
		size = 1;
		while (size < n)size *= 2;
		tree.resize(2 * size);
		build(a, 0, 0, size);
	}
	void self_set(int x, int lx, int rx, int val) {
		tree[x].sum = val * (rx - lx);
		tree[x].toSet = true;
		tree[x].setVal = val;
	}
	void propagate(int x, int lx, int rx) {
		if (rx - lx == 1)return;
		if (tree[x].toSet) {
			int mid = (rx + lx) / 2;
			self_set(2 * x + 1, lx, mid, tree[x].setVal), self_set(2 * x + 2, mid, rx, tree[x].setVal);
			tree[x].toSet = false;
		}
	}
	void set(int x, int lx, int rx, int l, int r, int val) {
		propagate(x, lx, rx);
		if (rx <= l || lx >= r) {
			return;
		}
		if (rx <= r && lx >= l) {
			self_set(x, lx, rx, val);
			return;
		}
		int mid = (lx + rx) / 2;
		set(2 * x + 1, lx, mid, l, r, val);
		set(2 * x + 2, mid, rx, l, r, val);
		tree[x].sum = tree[2 * x + 1].sum + tree[2 * x + 2].sum;
	}
	void set(int l, int r, int val) {
		set(0, 0, size, l, r, val);
	}
	int rangesum(int x, int lx, int rx, int l, int r) {
		propagate(x, lx, rx);
		if (rx <= l || lx >= r) {
			return 0;
		}
		if (rx <= r && lx >= l) {
			return tree[x].sum;
		}
		int mid = (lx + rx) / 2;
		int left = rangesum(2 * x + 1, lx, mid, l, r);
		int right = rangesum(2 * x + 2, mid, rx, l, r);
		return left + right;
	}
	int rangesum(int l, int r) {
		return rangesum(0, 0, size, l, r);
	}
};
