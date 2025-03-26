#include <iostream>
#include <queue>
using namespace std;

int A[101][101];
int distanceResult;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int N, M, X, Y, Z;

void bfs(int start_x, int start_y, int end_x, int end_y) {
	queue<pair<int, int> > q;
	queue<int> d; // 각 좌표까지의 거리를 저장하는 큐
	bool visited[101][101] = {false, };

	q.push(make_pair(start_x, start_y));
	d.push(0);
	visited[start_x][start_y] = true;

	while(!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		int cd = d.front();
		q.pop();
		d.pop();

		if (cx == end_x && cy == end_y) {
			distanceResult = cd;
			return;
		}

		for(int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (nx >= 1 && nx <= N && ny >= 1 && ny <= N) {
				if (!visited[nx][ny] && A[nx][ny] != 1) {
					visited[nx][ny] = true;
					q.push(make_pair(nx, ny));
					d.push(cd + 1);
				}
			}
		}
	}
	
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> X >> Y >> Z;

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	long result = 0;
	int last_c, last_d;
	for(int i = 0; i < M; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;

		if(i != 0) {
			bfs(last_d, last_c, b, a);
			result -= Z * distanceResult;
		}

		bfs(b, a, d, c);
		if (distanceResult <= 5) {
			result += X;
		} else {
			result += (X + (distanceResult - 5) * Y);
		}
		result -= Z * distanceResult;

		last_c = c;
		last_d = d;
	}
	cout << result;
	return 0;
}
