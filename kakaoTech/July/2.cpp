#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

vector<pair<long, long> > A;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	long N, M, K;
	cin >> N >> M >> K;

	A.resize(K + 1);
	for(int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = make_pair(a, b);
	}

	long min_v = LONG_MAX;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= M; j++) {
			long sum = 0;
			bool isOccupied = false;
			for(int k = 1; k <= K; k++) {
				if(i == A[k].first && j == A[k].second) {
					isOccupied = true;
					break;
				}
				sum += pow((i - A[k].first), 2) + pow((j - A[k].second), 2);
			}
			if(isOccupied) continue;
			min_v = min(min_v, sum);
		}
	}
	cout << min_v;
	return 0;
}
