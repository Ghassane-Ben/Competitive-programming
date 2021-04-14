vector<vector<int>>adj;
int n;
vector<char> color;
vector<int> parent;
int cycle_start, cycle_end;
set<int>ciclo; //posso usare vector se voglio intero ciclo in ordine
vector<int>visited;
vector<int>cnt;
bool dfs(int v, int par) { // passing vertex and its parent vertex
	color[v] = 1;
	for (int u : adj[v]) {
		if (u == par)
			continue; // skipping edge to parent vertex
		if (color[u] == 0) {
			parent[u] = v;
			if (dfs(u, parent[u]))
				return true;
		} else if (color[u] == 1) { //se grigio c'è ciclo
			cycle_end = v;
			cycle_start = u;
			return true;
		}
	}
	color[v] = 2; //coloro di nero e non c'è ciclo con questo vertice
	return false;
}

void find_cycle() {
	color.assign(n + 1, 0);
	parent.assign(n + 1, -1);
	cycle_start = -1;

	for (int v = 1; v <= n; v++) {
		if (color[v] == 0 && dfs(v, parent[v]))
			break;
	}

	if (cycle_start == -1) {
		return;
	}
	else {
		ciclo.insert(cycle_start);
		for (int v = cycle_end; v != cycle_start; v = parent[v])
			ciclo.insert(v);
		ciclo.insert(cycle_start);
	}
}