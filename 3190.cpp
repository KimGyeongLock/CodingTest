#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int> > vec; 
vector<int> sec;
vector<char> dir;
queue<pair<int, int> > q;

int N, K, L;
int cdir = 1; //동:1 서: 2 북: 3 남: 4

//bfs인줄 알았지만 구현
int playGame() {
    int count = 1;
    int x = 0, y = 0;

    while(1){
        // 현재 방향으로 머리 이동
        if(cdir == 1) y++;
        else if(cdir == 2) y--;
        else if(cdir == 3) x--;
        else if(cdir == 4) x++;

        // 범위 밖 또는 자기 몸에 부딪히면 게임 종료
        if(x < 0 || x >= N || y < 0 || y >= N || vec[x][y] == -1) break;

        q.push(make_pair(x, y));

        if(vec[x][y] != 1) { // 사과가 없는 경우
            if(q.size()>0) {
                pair<int, int> tail = q.front();
                q.pop();
                vec[tail.first][tail.second] = 0;
            }
        }
        vec[x][y] = -1;
        
        // 방향 전환 체크
        for(int i=0;i<L;i++) {
            if(sec[i] == count) {
                if(dir[i] == 'L') {
                    if(cdir == 1) cdir = 3;
                    else if(cdir == 2) cdir = 4;
                    else if(cdir == 3) cdir = 2;
                    else if(cdir == 4) cdir = 1;
                } else if(dir[i] == 'D') {
                    if(cdir == 1) cdir = 4;
                    else if(cdir == 2) cdir = 3;
                    else if(cdir == 3) cdir = 1;
                    else if(cdir == 4) cdir = 2;
                }
            }
        }
        count++;
    }
    return count;
}

int main() {
    /*
        사과를 먹으면 뱀 길이가 늘어난다.
        벽 또는 자기 자신의 몸과 부딪히면 겜이 끝
        NxN
        뱀의 위치(0,0), 뱀의 길이 = 1 오른쪽을 향함
        머리를 늘려 다음칸으로 이동
            사과가 있다면 사과는 없어지고 꼬리는 고정 => 길이 + 1
            사과가 없다면 꼬리를 당긴다. => 길이 고정

        n초 뒤 L(왼쪽) 또는 D(오른쪽)
    */

    cin >> N >> K;

    vec.assign(N, vector<int>(N, 0));
   
    for(int i=0;i<K;i++) {
        int a,b;
        cin >> a >> b;
        vec[a-1][b-1] = 1;
    }

    cin >> L;
    sec.resize(L);
    dir.resize(L);
    for(int i=0;i<L;i++) {
        cin >> sec[i] >> dir[i];
    }

    q.push(make_pair(0, 0));
    vec[0][0] = -1;

    int sec = playGame();
    cout << sec;
}
