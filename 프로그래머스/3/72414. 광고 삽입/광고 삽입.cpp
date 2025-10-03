#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> convert(string s) {
    int h1 = stoi(s.substr(0, 2));
    int m1 = stoi(s.substr(3, 2));
    int s1 = stoi(s.substr(6, 2));
    int h2 = stoi(s.substr(9, 2));
    int m2 = stoi(s.substr(12, 2));
    int s2 = stoi(s.substr(15, 2));
    
    return {3600 * h1 + 60 * m1 + s1, 3600 * h2 + 60 * m2 + s2};
}

int convert2(string s) {
    int h1 = stoi(s.substr(0, 2));
    int m1 = stoi(s.substr(3, 2));
    int s1 = stoi(s.substr(6, 2));
    return 3600 * h1 + 60 * m1 + s1;
}

string reconvert(int i) {
    int h1 = i / 3600;
    int m1 = (i % 3600) / 60;
    int s1 = (i % 3600) % 60;
    char buf[16];
    sprintf(buf, "%02d:%02d:%02d", h1, m1, s1);
    return string(buf);
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int t = convert2(play_time);
    vector<int> diff(t + 1, 0);
    vector<int> users(t + 2, 0);
    for (string s : logs) {
        vector<int> c = convert(s);
        diff[c[0]] += 1;
        diff[c[1]] -= 1;
    }
    
    for (int i = 0; i <= t; i++) {
        users[i + 1] = users[i] + diff[i];
    }
    
    vector<long> prefix(t + 3, 0);
    for (int i = 0; i <= t + 1; i++) {
        prefix[i + 1] = prefix[i] + users[i + 1]; 
    }
    
    int c = convert2(adv_time);
    long max_v = 0;
    int max_t;
    for (int i = 0; i + c <= t; i++) {
        if (max_v < prefix[i + c] - prefix[i]) {
            max_v = prefix[i + c] - prefix[i];
            max_t = i;
        }
    }
    
    string res = reconvert(max_t);
    
    return res;
}