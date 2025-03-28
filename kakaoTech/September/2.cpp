#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> a;
vector<vector<int> > adj;

int count = 1;

void bfs(int lang1, int lang2) {
	vector<bool> visited(N + 1);
	visited[1] = true;
	queue<int> q;
	q.push(1);
	count = 1;

	while(!q.empty()) {
		int cur = q.front();
		q.pop();
		for(int next : adj[cur]) {
			if (!visited[next] && (a[next] == lang1 || a[next] == lang2)) {
				visited[next] = true;
				q.push(next);
				count++;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	a.resize(N + 1);
	adj.resize(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> a[i];
	}

	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	int max_v = 0;
	for(int i = 1; i <= N; i++) {
		bfs(a[1], a[i]);
		max_v = max(max_v, count);
	}
	cout << max_v;
}
