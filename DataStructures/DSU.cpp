struct DSU {
    int n;
    vector<int> par;
    vector<int> sz;
    vector<int>mn, mx;
    DSU(int _n) : n(_n) {
        par.resize(n + 1), sz.resize(n + 1), mn.resize(n + 1), mx.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            par[i] = i, sz[i] = 1, mn[i] = i, mx[i] = i;
        }
    }
    int find(int a) {
        if (a == par[a])
            return a;
        return par[a] = find(par[a]); //set parent to every node in the path to the root (path compression)
    }
    void join(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        par[a] = b;
        mn[b] = min(mn[b], mn[a]);
        mx[b] = max(mx[b], mx[a]);
        sz[b] += sz[a];

    }
    int getsize(int a) {
        a = find(a);
        return sz[a];
    }

    int getmin(int a) {
        a = find(a);
        return mn[a];
    }

    int getmax(int a) {
        a = find(a);
        return mx[a];
    }

};