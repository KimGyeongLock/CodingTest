#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        int pos = 0;
        while (num) {
            if (num & 1) cout << pos << " ";
            num >>= 1;
            pos++;
        }
        cout << "\n";
    }

    return 0;
}