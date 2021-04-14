
dist[source] = 0;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int> >> q;
q.push({0, source});

while (!q.empty()) {

	int u = q.top().second;

	int d = q.top().first;

	q.pop();
	if (d != dist[u]) continue;

	for (auto it : adj[u]) {

		int v = it.first, w = it.second;

		if (dist[u] + w < dist[v]) {
			dist[v] = dist[u] + w;

			parent[v] = u;
			q.push({dist[v], v});




		}

	}

}