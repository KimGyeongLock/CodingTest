#include <string>
#include <vector>
#include <functional>

using namespace std;

const int rates[4] = {10, 20, 30, 40};
int m; 
vector<int> choice;
pair<int, int> best = {0, 0};

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer(2);
    m = emoticons.size();
    choice.resize(m, 0);
    
    function<void(int)> dfs = [&](int idx) {
        if (idx == m) {
            int cnt = 0;
            int total = 0;
            for (int i = 0; i < users.size(); i++) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    if (users[i][0] <= rates[choice[j]]) {
                        sum += emoticons[j] * (100 - rates[choice[j]]) / 100;
                        if(sum >= users[i][1]) {
                            cnt++;
                            break;
                        }
                    }
                }
                if(sum < users[i][1]) total += sum;
            }
            
            if (best.first < cnt) best = {cnt, total};
            else if (best.first == cnt && best.second < total) best = {cnt, total};
            return;
        }
        for (int k = 0; k < 4; k++) {
            choice[idx] = k; // 10, 20, 30, 40
            dfs(idx+1);
        }
    };
    
    
    dfs(0);
    return {best.first, best.second};
}