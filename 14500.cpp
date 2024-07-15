#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 504;
// (dx[?], dy[?]) => (1, 0), (-1, 0), (0, -1), (0, 1)
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, -1, 1};
//depth가 3인 dfs로 해결되는 애들
int makeStandardShape(int x, int y, int prev_x, int prev_y, int depth, int TetroMino[MAX][MAX], int &N, int &M){
  int answer = 0;
  if(depth == 3){
    return TetroMino[x][y];
  }
  for(int i = 0; i < 4; i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if(nx < 0 || ny < 0 || nx >= N || ny >= M) {
        continue;
      }
      if(prev_x == nx && prev_y == ny) {
        continue;
      }
      answer = max(answer, TetroMino[x][y] + makeStandardShape(nx, ny, x, y, depth+1, TetroMino, N, M));
    }
  return answer;
}
// ㅜ, ㅓ, ㅏ, ㅗ
int makeWOOShape(int x, int y, int N, int M, int answer, int Tetromino[MAX][MAX]){
    if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < M) {
         int tmp = Tetromino[x - 1][y] + Tetromino[x][y - 1] + Tetromino[x][y] + Tetromino[x][y + 1];
          answer = max(answer, tmp);
    }
    if (y - 1 >= 0 && x + 1 < N && y + 1 < M) {
         int tmp = Tetromino[x][y - 1] + Tetromino[x][y] + Tetromino[x][y + 1] + Tetromino[x + 1][y];
         answer = max(answer, tmp);
    }
    if (x - 1 >= 0 && y - 1 >= 0 && x + 1 < N) {
         int tmp = Tetromino[x - 1][y] + Tetromino[x][y - 1] + Tetromino[x][y] + Tetromino[x + 1][y];
          answer = max(answer, tmp);
    }
    if (x - 1 >= 0 && x + 1 < N && y + 1 < M) {
          int tmp = Tetromino[x - 1][y] + Tetromino[x][y] + Tetromino[x][y + 1] + Tetromino[x + 1][y];
          answer = max(answer, tmp);
    }
  return answer;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  int N, M;
  int Tetromino[MAX][MAX];
  int answer = 0;
  cin >> N >> M;
  for(int i = 0; i < N; i++){
    for(int j = 0; j < M; j++){
      cin >> Tetromino[i][j];
    }
  }
  for(int i = 0; i < N; i++) {
  	for(int j = 0; j <= M; j++) {
      answer = max(answer, makeStandardShape(i, j, -1, -1, 0, Tetromino, N, M));
      answer = max(answer, makeWOOShape(i, j, N, M, 0, Tetromino));
    }
  }
  cout << answer << "\n";
}