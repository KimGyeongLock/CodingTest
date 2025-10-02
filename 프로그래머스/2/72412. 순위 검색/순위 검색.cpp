#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string s, char del = ' ') {
    vector<string> res;
    stringstream ss(s);
    string word;
    while(getline(ss, word, del)) {
        res.push_back(word);
    }
    return res;
}
vector<int> result[4][3][3][3];
int cnt = 0;
void dfs(const vector<string>& vec, int depth, vector<int>& list, int idx) {
    if (depth == 4) {
        auto it = lower_bound(result[list[0]][list[1]][list[2]][list[3]].begin(), result[list[0]][list[1]][list[2]][list[3]].end(), stoi(vec[7]));
        cnt += (int)(result[list[0]][list[1]][list[2]][list[3]].end() - it);
        return;
    } 
    
    if (vec[idx] != "-") {
        if (vec[idx] == "cpp" || vec[idx] == "backend" || vec[idx] == "junior" 
            || vec[idx] == "chicken") list[depth] = 0;
        else if (vec[idx] == "java" || vec[idx] == "frontend" || vec[idx] == "senior" 
            || vec[idx] == "pizza") list[depth] = 1;
        else if (vec[idx] == "python") list[depth] = 2;
        
        dfs(vec, depth + 1, list, idx + 2);
    } else {
        if (depth == 0) {
           for (int i = 0; i < 3; i++) {
                list[depth] = i;
                dfs(vec, depth + 1, list, idx + 2);
            } 
        } else {
            for (int i = 0; i < 2; i++) {
                list[depth] = i;
                dfs(vec, depth + 1, list, idx + 2);
            }
        }
        
    }
}

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    for (string str : info) {
        vector<string> vec = split(str);
        int a, b, c, d;
        if (vec[0] == "cpp") a = 0;
        else if (vec[0] == "java") a = 1;
        else if (vec[0] == "python") a = 2;
        else a = 3;
        
        if (vec[1] == "backend") b = 0;
        else if (vec[1] == "frontend") b = 1;
        else b = 2;
        
        if (vec[2] == "junior") c = 0;
        else if (vec[2] == "senior") c = 1;
        else c = 2;
        
        if (vec[3] == "chicken") d = 0;
        else if (vec[3] == "pizza") d = 1;
        else d = 2;
        
        result[a][b][c][d].push_back(stoi(vec[4]));
    }
    
     for (int a = 0; a < 4; ++a)
        for (int b = 0; b < 3; ++b)
            for (int c = 0; c < 3; ++c)
                for (int d = 0; d < 3; ++d)
                    sort(result[a][b][c][d].begin(), result[a][b][c][d].end());

    
    for (string q : query) {
        vector<string> vec = split(q);
        cnt = 0;
        vector<int> tmp = {-1, -1, -1, -1};
        dfs(vec, 0, tmp, 0);
        answer.push_back(cnt);
    }
    
    return answer;
}