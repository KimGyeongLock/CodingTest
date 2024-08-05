#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vec;
vector<int> order;
vector<int> dice (6, 0);

int main(){
    /*
        NxM - 각 칸에 정수
        주사위 전개도
          2
        4 1 3
          5
          6
        지도 (r,c)
        1이 윗면, 3이 동쪽
        놓여져 있는 곳 (x,y)
        주사위 모든 면 0
            지도 이동한 칸 숫자가 0이면 주사위 밑면을 복사
            0이 아니면 칸에 있는 숫자가 주사위 밑면에 복사 -> 칸의 숫자 = 0
        주사위 상단의 숫자를 출력 
          2
        4 1 3
          5
          6

      오른쪽(1) 1->3 3->6 4->1 6->4
        2
      6 4 1
        5
        3  
      왼쪽(2) 1->4 3->1 4->6 6->3
        2
      1 3 6
        5
        4
      뒤(3) 1->2 2->6 5->1 6->5
        1
      4 5 3
        6
        2
      앞(4) 1->5 2->1 5->6 6->2
        6
      4 2 3
        1
        5
    */
    int N, M, x, y, K;
    cin >> N >> M >> x >> y >> K;
    vec.assign(N, vector<int>(M));

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> vec[i][j];
        }
    }
    order.resize(K);
    for(int i=0;i<K;i++) {
        cin >> order[i];
    }
    for(int i=0;i<order.size();i++) {
        int current_bottom = 5; // 6인데 index = 5;

        if(order[i] == 1) { //동
          y++;
          if(y >= M) {
            y--;
            continue;
          }
          int one = dice[0];
          int three = dice[2];
          int four = dice[3];
          int six = dice[5];

          dice[2] = one;
          dice[5] = three;
          dice[0] = four;
          dice[3] = six;
        }
        else if(order[i] == 2) { //서
          y--;
          if(y < 0) {
            y++;
            continue;
          }
          int one = dice[0];
          int three = dice[2];
          int four = dice[3];
          int six = dice[5];

          dice[3] = one;
          dice[0] = three;
          dice[5] = four;
          dice[2] = six;
        } else if (order[i] == 3){ //북
          x--;
          if(x < 0) {
            x++;
            continue;
          }
          int one = dice[0];
          int two = dice[1];
          int five = dice[4];
          int six = dice[5];

          dice[1] = one;
          dice[5] = two;
          dice[0] = five;
          dice[4] = six;
        } else if (order[i] == 4) { //남
          x++;
          if(x >= N) {
            x--;
            continue;
          }
          int one = dice[0];
          int two = dice[1];
          int five = dice[4];
          int six = dice[5];

          dice[4] = one;
          dice[0] = two;
          dice[5] = five;
          dice[1] = six;
        } 
        
        if(vec[x][y] == 0) {
            // 주사위 밑면을 지도에 복사
            vec[x][y] = dice[5];
        } else {
            // 지도 숫자를 밑면에 복사, 칸의 숫자 = 0
            dice[5] = vec[x][y];
            vec[x][y] = 0;
        }
        cout << dice[0] << "\n"; 
    }
}