#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>

using namespace std;

vector<string> split(const string& s, char delimiter) {
    vector<string> res;
    stringstream ss(s);
    string word;
    while (getline(ss, word, delimiter)) { 
        res.push_back(word);
    }
    return res;
}
unordered_map<char, int> mp;
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    for (string t : terms) {
        vector<string> vec = split(t, ' ');
        mp[vec[0][0]] = stoi(vec[1]);
    }
    
    int t_y = stoi(today.substr(0, 4));
    int t_m = stoi(today.substr(5, 2));
    int t_d = stoi(today.substr(8, 2));
    
    for (int i = 0; i < privacies.size(); i++) {
        string s = privacies[i];
        int y = stoi(s.substr(0, 4));
        int m = stoi(s.substr(5, 2));
        int d = stoi(s.substr(8, 2));
        char c = s[s.length() - 1];
        int term = mp[c];
        
        m += term;
        while (m > 12) {
            m -= 12;
            y += 1;
        }
        
        if (t_y > y) answer.push_back(i+1);
        else if (t_y == y && t_m > m) answer.push_back(i+1);
        else if (t_y == y && t_m == m && t_d >= d) answer.push_back(i+1);
    }
    
    return answer;
}