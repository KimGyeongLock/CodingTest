#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    int r, c, d;
    cin >> r >> c >> d;
    // 0: 북쪽, 1: 동쪽, 2: 남쪽, 3:서쪽
    vector<vector<int> > vec(N, vector<int>(M));

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> vec[i][j];
        }
    }
        
    int count = 0;
    while(1) {
        if(vec[r][c] == 0 || vec[r][c] == 2) {
            if(vec[r][c] == 0) {
                count++;
                vec[r][c] = 2;
            }
            if(vec[r-1][c] == 0 || vec[r+1][c] == 0 || vec[r][c-1] == 0 || vec[r][c+1] == 0) {
                d -= 1;
                if(d<0) d = 3;
                if(d==0 && vec[r-1][c] == 0) r--;
                if(d==1 && vec[r][c+1] == 0) c++;
                if(d==2 && vec[r+1][c] == 0) r++;
                if(d==3 && vec[r][c-1] == 0) c--;
            } else {
                // cout << d << vec[r+1][c] << vec[r-1][c] << vec[r][c-1] << vec[r][c+1];
                if(d==0 && vec[r+1][c] == 2) r++;
                else if(d==0 && vec[r+1][c] == 1) break;
                if(d==1 && vec[r][c-1] == 2) c--;
                else if(d==1 && vec[r][c-1] == 1) break;
                if(d==2 && vec[r-1][c] == 2) r--;
                else if(d==2 && vec[r-1][c] == 1) break;
                if(d==3 && vec[r][c+1] == 2) c++;
                else if(d==3 && vec[r][c+1] == 1) break;
            }
        }
    }
    cout << count;
}

//가독성 좋은 코드
// #include <iostream>
// #include <vector>

// using namespace std;

// int main()
// {
//     int N, M;
//     cin >> N >> M;
//     int r, c, d;
//     cin >> r >> c >> d;

//     // 0: 북쪽, 1: 동쪽, 2: 남쪽, 3: 서쪽
//     vector<vector<int>> map(N, vector<int>(M));

//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < M; j++) {
//             cin >> map[i][j];
//         }
//     }

//     int cleaned = 0;
//     while (true) {
//         // 현재 위치 청소
//         if (map[r][c] == 0) {
//             cleaned++;
//             map[r][c] = 2; // 2는 청소 완료를 의미
//         }

//         // 네 방향 중 청소되지 않은 구역이 있는지 확인
//         bool has_uncleaned_adjacent = false;
//         for (int i = 0; i < 4; i++) {
//             int next_d = (d + 3) % 4; // 왼쪽으로 회전
//             int next_r = r, next_c = c;
//             if (next_d == 0) next_r--;
//             if (next_d == 1) next_c++;
//             if (next_d == 2) next_r++;
//             if (next_d == 3) next_c--;

//             if (map[next_r][next_c] == 0) {
//                 r = next_r;
//                 c = next_c;
//                 d = next_d;
//                 has_uncleaned_adjacent = true;
//                 break;
//             } else {
//                 d = next_d;
//             }
//         }

//         if (!has_uncleaned_adjacent) {
//             // 네 방향 모두 청소되었거나 벽인 경우
//             int back_r = r, back_c = c;
//             if (d == 0) back_r++;
//             if (d == 1) back_c--;
//             if (d == 2) back_r--;
//             if (d == 3) back_c++;

//             if (map[back_r][back_c] == 1) {
//                 // 후진할 수 없는 경우 (벽)
//                 break;
//             } else {
//                 // 후진
//                 r = back_r;
//                 c = back_c;
//             }
//         }
//     }

//     cout << cleaned;
//     return 0;
// }
