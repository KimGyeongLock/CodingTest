#include <iostream>
using namespace std;

int main() {
	long N;
	cin >> N;

	int five = 0;
	int count = 0;
	while(N > 0) {
		count += N / 5;
		N = N / 5;
	}
	cout << count;
	return 0;
}
