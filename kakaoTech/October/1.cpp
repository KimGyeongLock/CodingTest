#include <iostream>
#include <vector>
using namespace std;

vector<long> A;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	A.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	long r = A[0];
	int index = 0;
	long count = 1;
	while(r > 0) {
		if(r >= 10) {
			long block = r / 10;
			r %= 10;
			if (r <= 0 && index < N - 1) {
				r = A[++index];
			}
			count += block * 4;
		} else {
			r -= ((count - 1) % 4) + 1;
			if (r <= 0 && index < N - 1) {
				r = A[++index];
			} 
			count++;
		}
	}
	cout << count - 1;
}
