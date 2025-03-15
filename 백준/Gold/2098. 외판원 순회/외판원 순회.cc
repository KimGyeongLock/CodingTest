#include <iostream>

using namespace std;

int W[16][16];
int D[16][(1 << 16)];
int INF = 1000000 * 16 + 1;


int N;
int tsp(int c, int v) {
    if (v == (1 << N) - 1) { //모든 노드를 방문했을 때
        return W[c][0] == 0 ? INF : W[c][0];
    }
    if (D[c][v] != 0) { //이미 방문한 노드 -> 메모이제이션
        return D[c][v];
    }
    
    int min_val = INF;
    for(int i = 0; i < N; i++) {
        if ((v & (1 << i)) == 0 && W[c][i] != 0) { //방문한 적 없고 갈 수 있는 도시
            min_val = min(min_val, tsp(i, (v | (1 << i))) + W[c][i]);

        }
    }
    D[c][v] = min_val;
    return D[c][v];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> W[i][j];
        }
    }
    cout << tsp(0, 1);

}