#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    string answer = "~";

    int length = s.length();
    for(int i = 1; i < length; i++) {
        for(int j = i + 1; j < length; j++) {
            string part1 = s.substr(0, i);
            string part2 = s.substr(i, j - i);
            string part3 = s.substr(j);

            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            reverse(part3.begin(), part3.end());

            string combined = part1 + part2 + part3;

            if (answer > combined) {
                answer = combined;
            }
        }
    }
    cout << answer;
}