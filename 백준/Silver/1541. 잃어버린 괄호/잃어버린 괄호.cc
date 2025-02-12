#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> split(string input, char delimiter) {
    vector<string> result;
    stringstream mystream(input);
    string splitdata;

    while (getline(mystream, splitdata, delimiter)) {
        result.push_back(splitdata);
    }

    return result;
}

int main()
{
    string s;
    cin >> s;

    vector<string> str = split(s, '-');

    int ans = 0;
    for(int i = 0; i < str.size(); i++) {
        vector<string> temp = split(str[i], '+');
        int sum = 0;
        for(int j = 0; j < temp.size(); j++) {
            sum += stoi(temp[j]);
        }

        if (i == 0) {
            ans += sum;
        } else {
            ans -= sum;
        }
    }

    cout << ans;
}