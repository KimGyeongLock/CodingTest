#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

vector<vector<int> > A;
vector<vector<int> > visited;
vector<pair<int, int> > lst;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

int N, L, R;
int sum = 0;
int cnt = 0;

void func(int x, int y) {
    visited[x][y] = 1;
    sum += A[x][y];
    cnt++;
    lst.push_back(make_pair(x, y));
    
    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        
        if(nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == 0) {
            int diff = abs(A[x][y] - A[nx][ny]);
            if(diff >= L && diff <= R) {
                func(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N >> L >> R;
    A.resize(N, vector<int>(N));
    visited.resize(N, vector<int>(N));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }
    
    int days = 0;
    while(true) {
        bool movement = false;
        visited.assign(N, vector<int>(N, 0));
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(visited[i][j] == 0) {
                    sum = 0;
                    cnt = 0;
                    lst.clear();
                    
                    func(i, j);
                    
                    if(cnt > 1) { // cnt 자기 빼고 2이상
                        movement = true;
                        int newPopulation = sum / cnt;
                        for(int k=0; k<lst.size(); k++) {
                            A[lst[k].first][lst[k].second] = newPopulation;
                        }
                    }
                }
            }
        }
        
        if(!movement) break; //cnt가 1 or 0일때
        days++;
    }
    
    cout << days << endl;
    return 0;
}
