#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long> A;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	cin >> N;

	A.resize(N);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A.begin(), A.end());

	long count = 0;
	for(int k = N - 1; k >= 2; k--) {
		int i = 0;
		int j = k - 1;
		while(i < j) {
			if(A[i] + A[j] >= A[k]) {
				count += (j - i);
				j--;
			} else {
				i++;
			}
		}
	}
	cout << count;
}
