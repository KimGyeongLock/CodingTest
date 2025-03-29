#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

vector<int> parent;
vector<tuple<int, int, int>> edges;

int find(int a) {
	if (a == parent[a]) {
		return a;
	}

	return parent[a] = find(parent[a]);
}

void unionfunc(int a, int b) {
	a = find(a);
	b = find(b);

	if(a != b) {
		parent[b] = a;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M, K;
	cin >> N >> M;

	parent.resize(N + 1);

	for(int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	
	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		unionfunc(a, b);
	}
	cin >> K;

	for(int i = 0; i < K; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edges.push_back(make_tuple(w, u, v));
	}

	sort(edges.begin(), edges.end());

	long result = 0;
	for(tuple<int, int, int> edge : edges) {
		int w = get<0>(edge);
		int u = get<1>(edge);
		int v = get<2>(edge);
		if (find(u) != find(v)) {
			unionfunc(u, v);
			result += w;
		}
	}

	for(int i = 1; i <= N; i++) {
		if(find(1) != find(i)) {
			cout << -1;
			return 0;
		}
	}
	
	cout << result;
	return 0;
}
