#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
// #include <iomanip>


using namespace std;

int N;
vector<vector<int> > vec;

const int dx[4] = {1, -1, 0, 0};  // 방향: 아래, 위, 오른쪽, 왼쪽
const int dy[4] = {0, 0, 1, -1};  // 방향: 아래, 위, 오른쪽, 왼쪽

int size_v = 2;
int eat_v = 0;
int time_v = 0;

// BFS를 사용하여 가장 가까운 먹이를 찾는 함수
pair<int, pair<int, int> > find_feed(int x, int y) {
    vector<vector<int> > dist(N, vector<int>(N, -1)); // -1은 아직 방문하지 않은 셀을 의미함, 셀은 거리가 들어간다.
    queue<pair<int, int> > q; // BFS에선 queue를 사용 - queue에는 밟는 칸을 넣음 (물고기 위치X)
    q.push(make_pair(x, y));
    dist[x][y] = 0; // 현재 위치, 거리 = 0

    pair<int, int> target = make_pair(-1, -1); // 이전 물고기의 위치 좌표
    int min_dist = INT_MAX;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        int cd = dist[cx][cy]; 
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            // (범위 밖 제외) && (방문하지 않은 곳) && (자기보다 덩치가 작은 물고기) || (0 빈칸)
            if (nx >= 0 && nx < N && ny >= 0 && ny < N && dist[nx][ny] == -1 && vec[nx][ny] <= size_v) {
                dist[nx][ny] = cd + 1; // cd 제자리에서 인접(+1)한 자리 

                // 물고기가 있는 자리라면
                if (vec[nx][ny] > 0 && vec[nx][ny] < size_v) {
                    // 최소 거리보다 작으면 교체
                    if (dist[nx][ny] < min_dist) {
                        min_dist = dist[nx][ny];
                        target = make_pair(nx, ny); // 이전 물고기
                    // 최소 거리가 같을 때 
                    } else if (dist[nx][ny] == min_dist) {
                        // 이전 물고기보다 현재 물고기가 우선순위가 더 위 또는 왼쪽
                        if (nx < target.first || (nx == target.first && ny < target.second)) {
                            target = make_pair(nx, ny);
                        }
                    }
                }
                q.push(make_pair(nx, ny));
            }
        }
    }

    if (target.first == -1 && target.second == -1) {
        return make_pair(-1, make_pair(-1, -1));
    }

    // cout << "------------------------------------\n";
    // for(int i=0;i<N;i++) {
    //     for(int j=0;j<N;j++) {
    //         if (dist[i][j] == -1) {
    //             cout << setw(2) << setfill(' ') << "-1" << " ";
    //         } else {
    //             cout << setw(2) << setfill(' ') << dist[i][j] << " ";
    //         }
    //     }
    //     cout << "\n";
    // }

    return make_pair(min_dist, target);
}

void moveSharkAndEat(int x, int y) {
    while (true) {
        pair<int, pair<int, int> > result = find_feed(x, y);
        int min_dist = result.first; // 최소 거리
        pair<int, int> target = result.second; // 최소 거리의 물고기가 있는 좌표

        if (min_dist == -1) break; // 최소 거리가 -1 을 return 하면 종료

        int next_x = target.first; 
        int next_y = target.second;

        vec[next_x][next_y] = 0; // 물고기 먹었으니 빈칸(0)으로 대체
        time_v += min_dist;
        eat_v++;

        if (eat_v == size_v) {
            size_v++;
            eat_v = 0;
        }

        x = next_x;
        y = next_y;
    }
}

int main() {
    cin >> N;
    pair<int, int> shark;
    vec.assign(N, vector<int>(N));

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> vec[i][j];
            if (vec[i][j] == 9) {
                shark = make_pair(i, j);
                vec[i][j] = 0;
            }
        }
    }

    moveSharkAndEat(shark.first, shark.second);
    cout << time_v;
}
