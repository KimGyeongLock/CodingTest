#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool palindorme(int n) {
    string s = to_string(n);
    int start = 0;
    int end = s.length() - 1;

    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        } else {
            start++;
            end--;
        }
    }
    return true;
}

int main()
{
    int N;
    cin >> N;

    vector<int> A(10000001);

    for(int i = 2; i < 10000001; i++) {
        A[i] = i;
    }

    for(int i = 2; i <= sqrt(10000001); i++) {
        if (A[i] == 0) continue;
        for(int j = i + i; j < 10000001; j += i) {
            A[j] = 0;
        }
    }

    for(int i = N;; i++) {
        if (A[i] != 0 && palindorme(A[i])) {
            cout << A[i];
            break;
        }
    }
}