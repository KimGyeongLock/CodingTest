#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    int n = players.size();
    vector<int> server(n, 0);
    for (int i = 0; i < n; i++) {
        if (players[i] >= m && players[i] > m * server[i]) {
            int add = players[i] / m - server[i];
            answer += add;
            for (int j = 0; j < k && i + j < n; j++) {
                server[i + j] += add;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << players[i] << " " << server[i] << "\n";
    }
    
    return answer;
}