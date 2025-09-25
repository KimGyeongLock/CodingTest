#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

vector<string> split(string str, char del) {
    vector<string> res;
    stringstream ss(str);
    string word;
    while (getline(ss, word, del)) {
        res.push_back(word);
    }
    return res;
}

int diff(string a, string b) {
    int ah, am, bh, bm;
    ah = stoi(a.substr(0, 2));
    am = stoi(a.substr(3, 2));
    bh = stoi(b.substr(0, 2));
    bm = stoi(b.substr(3, 2));
    return ah * 60 + am - (bh * 60 + bm);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> t;
    
    for (string s : records) {
        vector<string> vec = split(s, ' ');
        string time = vec[0];
        string number = vec[1];
        t[number].push_back(time);
    }
    
    for (auto vec : t) {
        vector<string> v = vec.second;
        if (v.size() % 2 != 0) v.push_back("23:59");
        int sum = 0;
        for (int i = 0; i < v.size(); i += 2) {
            sum += diff(v[i + 1], v[i]);
        }
        if (sum <= fees[0]) {
            answer.push_back(fees[1]);
        } else {
            int total = fees[1];
            total += (ceil((double)(sum - fees[0]) / fees[2])) * fees[3];
            answer.push_back(total);
        }
    }

    return answer;
}