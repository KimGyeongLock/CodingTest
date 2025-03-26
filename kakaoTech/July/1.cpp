#include <iostream>
#include <vector>
using namespace std;

vector<long> H;
vector<char> D;

int main() {

	int N, M, S, Q;
	cin >> N >> M >> S;

	H.resize(N + 1);
	for(int i = 1; i <= N; i++) {
		cin >> H[i];
	}
	cin >> Q;
	D.resize(Q + 1);

	for(int i = 1; i <= Q; i++) {
		cin >> D[i];
	}

	long sum = 0;
	int index = S;
	long offset = 0;
	for(int i = 1; i <= Q; i++) {
		//1.
		long realHight = H[index] + offset;
		if (realHight >= M) {
			sum += realHight;
			H[index] = -offset;
		}
		//2.
		if (D[i] == 'L') {
			if (index == 1) {
				index = N;
			} else {
				index--;
			}
		} else if (D[i] == 'R') {
			if (index == N) {
				index = 1;
			} else {
				index++;
			}
		} 
		//3.
		offset++;
	}
	cout << sum;
	return 0;
}
