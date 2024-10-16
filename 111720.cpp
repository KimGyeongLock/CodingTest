#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    string str;
    cin >> str;

    int result = 0;
    for(int i=0;i<N;i++) {
        result += str[i] - '0';
    }
    cout << result;
}