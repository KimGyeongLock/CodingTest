#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T;

    for(int i = 0; i < T; i++) {
        int A, B;
        cin >> A >> B;

        int min, max;
        if (A >= B) {
            max = A;
            min = B;
        } else {
            max = B;
            min = A;
        }

        while (max % min != 0) {
            int temp = min;
            min = max % min;
            max = temp;
        }

        cout << (A * B / min) << "\n";
    }
}