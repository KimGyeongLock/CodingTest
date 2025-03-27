#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int N;
	cin >> N;

	A.resize(N);
	int one_count = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i].first;
		A[i].second = i + 1;
	}

	sort(A.begin(), A.end());

	bool zero = false;
	for(int i = 0; i < N; i++) {
		if (A[i].first - i <= 0) {
			zero = true;
			break;
		}
	}

	if (zero) {
		for(int i = 1; i <= N; i++) {
			cout << i << " ";
		}
	} else {
		for(int i = 0; i < N; i++) {
			cout << A[i].second << " ";
		}
	}
	
	return 0;
}
