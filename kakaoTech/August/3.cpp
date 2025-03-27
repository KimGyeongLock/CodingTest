#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<int> > A;
int N;

pair<int, int> bfs(int start) {
	vector<int> dist(N + 1, INT_MAX);
	queue<int> myqueue;
	myqueue.push(start);
	dist[start] = 0;

	while(!myqueue.empty()) {
		int cur = myqueue.front();
		myqueue.pop();

		for(int nxt : A[cur]) {
			if (dist[nxt] == INT_MAX) {
				dist[nxt] = dist[cur] + 1;
				myqueue.push(nxt);
			}
		}
	}

	int max_dist = 0;
	int max_idx;
	for(int i = 1; i <= N; i++) {
		if (dist[i] != INT_MAX && max_dist < dist[i]) {
			max_dist = dist[i];
			max_idx = i;
		}
	}
	return make_pair(max_idx, max_dist);
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;

	A.resize(N + 1);
	for(int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	if (N == 1) {
		cout << 1;
		return 0;
	}

	pair<int, int> X = bfs(1);

	pair<int, int> Y = bfs(X.first);

	cout << Y.second + 1;
	return 0;
}
