#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <queue>

using namespace std;

vector<vector<int> > vec;
map<int, vector<pair<int, int> > > mp;

int size_v = 2;

int time_v = 0;

const int dx[4] = {1, -1, 0, 0};  // 방향: 아래, 위, 오른쪽, 왼쪽
const int dy[4] = {0, 0, 1, -1};  // 방향: 아래, 위, 오른쪽, 왼쪽


int distance(int x1, int y1, int x2, int y2) { // (2, 1) - (0, 2)
    int N = vec.size();
    vector<vector<int> > dist(N, vector<int>(N, -1));  // -1은 아직 방문하지 않은 셀을 의미함
    
    queue<pair<int, int> > q;
    q.push(make_pair(x1, y1));
    dist[x1][y1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 목표 위치에 도달했으면 거리 반환
        if (x == x2 && y == y2) {
            return dist[x][y];
        }

        // 이웃 셀 탐색
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 이웃 셀이 격자 경계 내에 있고 방문하지 않았으며 접근 가능한 셀인지 확인
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1) {
                if (vec[nx][ny] <= size_v) {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
    
    // 목표 위치에 도달할 수 없으면 -1 반환
    return -1;
}

void func(int x, int y, int index) {
    int min_v = INT_MAX;
    int next_x, next_y;
    for(int i=0;i<mp[index].size();i++) {
        cout << x  << " " << y << " " << mp[index][i].first << " " << mp[index][i].second << "\n";
        int dist = distance(x, y, mp[index][i].first, mp[index][i].second);
        if(min_v == dist) {
            // 거리가 같다면 위, 왼쪽 순

            if(next_y < mp[index][i].second) {
                min_v = dist;
                next_x = mp[index][i].first;
                next_y = mp[index][i].second;
            } else if (next_y == mp[index][i].second && next_x < mp[index][i].first) {
                min_v = dist;
                next_x = mp[index][i].first;
                next_y = mp[index][i].second;
            } 
            
        } else if (min_v > dist) {
            min_v = dist;
            next_x = mp[index][i].first;
            next_y = mp[index][i].second;
        }
    }
       
    if(mp[index].size() <= 0 || index > 6) return;

    func(next_x, next_y, index++);

}

int main()
{
    /* 구현 - 완전탐색
        기능 요구사항
        NxN => 물고기 M, 아기상어 1마리
        아기상어 크기 = 2 , 1초에 상하좌우 이동
        자신 보다 큰 물고기가 있는 곳은 지나갈 수 없다.
        자신과 같은 물고기는 먹을 수 없다. 하지만 지나갈 수 있다
        자신보다 작은 물고기는 먹고 지나가고

        더이상 먹을 수 있는 물고기가 없다 - 엄마 상어에게 도움 => 끝
        가장 가까운 순으로 물고기 먹음
        거리는 최소 거리, 거리가 같다면 위 , 왼쪽 순
        아기상어 이동 1초
        자신의 크기와 같은 수의 물고기 먹을 때 마다 크기 1 증가
        몇초 동안 버티는지

        0: 빈 칸
        1, 2, 3, 4, 5, 6: 칸에 있는 물고기의 크기
        9: 아기 상어의 위치
    */ 

    int N;
    cin >> N;
    vec.resize(N, vector<int>(N));
    int x, y;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> vec[i][j];
            if(vec[i][j] == 9) {
                x = i;
                y = j;
            } else if (vec[i][j] > 0) {
                mp[vec[i][j]].push_back(make_pair(i, j));
            }

        }
    }
    // func(x, y, 1);

    cout << distance(2, 1, 0, 2);

    cout << time_v;
}