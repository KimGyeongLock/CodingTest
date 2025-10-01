#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(int n, int k, vector<string> cmd) {    
    vector<int> prev(n), next(n);
    for (int i = 0; i < n; i++) {
        prev[i] = i - 1;
        next[i] = (i == n - 1 ? -1 : i + 1);
    }
    vector<char> list(n, 'O');
    vector<int> deleted;
    
    for (const string& s : cmd) {
        if (s[0] == 'U') {
            int x = stoi(s.substr(2));
            while(x--) {
                k = prev[k];
            }
        } else if (s[0] == 'D') {
            int x = stoi(s.substr(2));
            while(x--) {
                k = next[k];
            }
        } else if (s[0] == 'C') {
            deleted.push_back(k);
            list[k] = 'X';
            int pk = prev[k];
            int nk = next[k];
            
            if (pk != -1) next[pk] = nk;
            if (nk != -1) prev[nk] = pk;
            
            k = (nk != -1) ? nk : pk;
        } else if (s[0] == 'Z') {
            int z = deleted.back(); deleted.pop_back();
            list[z] = 'O';
            
            int pz = prev[z];
            int nz = next[z];
            
            if (pz != -1) next[pz] = z;
            if (nz != -1) prev[nz] = z;
        }
    }
    
    return string(list.begin(), list.end());
}