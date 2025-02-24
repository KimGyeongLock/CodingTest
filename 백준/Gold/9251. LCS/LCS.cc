#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int s1length = s1.length();
    int s2length = s2.length();

    v.resize(s1length + 1, vector<int>(s2length + 1, 0));

    int count = 0;
    for(int i = 1; i <= s1length; i++) {
        for(int j = 1; j <= s2length; j++) {
            if(s1[i-1] == s2[j-1]) {
                v[i][j] = v[i-1][j-1] + 1;
            } else {
                v[i][j] = max(v[i-1][j], v[i][j-1]);
            }
        }
    }


    int i = s1length;
    int j = s2length;
    vector<char> result;
    while(v[i][j] != 0) {
        if (v[i][j] == v[i][j-1]) {
            j--;
        } else if (v[i][j] == v[i-1][j]) {
            i--;
        } else {
            i--;
            j--;
            result.push_back(s1[i]);
        }
    }

    // while(!result.empty()) {
    //     char c = result.back();
    //     result.pop_back();
    //     cout << c << " ";
    // }
    cout << result.size();
}