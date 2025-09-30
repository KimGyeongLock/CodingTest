#include <string>
#include <vector>

using namespace std;

bool checkRoom(const vector<string>& a) {
    
    int dx1[4] = {1, -1, 0, 0};
    int dy1[4] = {0, 0, 1, -1};
    
    int dx2[4] = {2, -2, 0, 0};
    int dy2[4] = {0, 0, 2, -2};
    
    int dx3[4] = {1, 1, -1, -1};
    int dy3[4] = {1, -1, 1, -1};
    
    for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 5; y++) {
            if (a[x][y] != 'P') continue;
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx1[k]; int ny = y + dy1[k];
                if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && a[nx][ny] == 'P') return false;
            }
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx2[k]; int ny = y + dy2[k];
                if (!(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && a[nx][ny] == 'P')) continue;
                nx = x + dx1[k]; ny = y + dy1[k];
                if (a[nx][ny] != 'X') return false;
            }
            
            for (int k = 0; k < 4; k++) {
                int nx = x + dx3[k]; int ny = y + dy3[k];
                if (!(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && a[nx][ny] == 'P')) continue;
                if (a[x][ny] != 'X' || a[nx][y] != 'X') return false;
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for (auto& room : places) {
        answer.push_back(checkRoom(room) ? 1 : 0);
    }
    return answer;
}