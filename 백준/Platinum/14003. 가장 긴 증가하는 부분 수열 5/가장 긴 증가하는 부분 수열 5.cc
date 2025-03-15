#include <iostream>

using namespace std;

int N;
int A[1000001];
int B[1000001];
int D[1000001];
int ans[1000001];
int binarysearch(int l, int r, int now) {
    int mid;

    while (l < r) {
        mid = (l + r) / 2;
        if (B[mid] < now) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    return l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    B[1] = A[1];
    D[1] = 1;
    int maxLength = 1;
    int index;
    for(int i = 2; i <= N; i++) {
        if (B[maxLength] < A[i]) { //수열로 포함
            maxLength++;
            B[maxLength] = A[i];
            D[i] = maxLength;
        } else {
            index = binarysearch(1, maxLength, A[i]);
            B[index] = A[i];
            D[i] = index;
        }
    }

    cout << maxLength << "\n";

    index = maxLength;
    int x = B[maxLength] + 1;
    for(int i = N; i >= 1; i--) {
        if (D[i] == index && A[i] < x) {
            ans[index] = A[i];
            x = A[i];
            index--;
        }
    }
    for(int i = 1; i <= maxLength; i++) {
        cout << ans[i] << " ";
    }
}