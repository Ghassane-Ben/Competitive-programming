//O(n+m) complexity kosaraju's algorithm

vector<int>adj[maxn];
vector<int>gr[maxn]; //reverse graph
stack<int>st;  //stack to put nodes when finished processing
vector<int>component;
vector<bool>visited;

void dfs1(int v) {
	visited[v] = true;
	for (auto it : adj[v]) {
		if (!visited[it])
			dfs1(it);
	}
	st.push(v);
}
void dfs2(int v) {
	visited[v] = true;
	component.push_back(v);
	for (auto it : gr[v]) {
		if (!visited[it]) {
			dfs2(it);
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int m;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		gr[b].push_back(a);
	}
	visited.assign(n + 1, false);
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs1(i);
		}
	}

	visited.assign(n + 1, false);
	//we start from a "root" in the reversed graph and put every reachable vertex in the current scc
	for (int i = 1; i <= n; i++) {
		int v = st.top();
		st.pop();
		if (!visited[v]) {
			dfs2(v);
			//process component
			component.clear();
		}
	}



}

