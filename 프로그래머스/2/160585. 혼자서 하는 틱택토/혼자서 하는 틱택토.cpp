#include <string>
#include <vector>

using namespace std;

static bool win(const vector<string>& b, char c) {
    // rows
    for (int i = 0; i < 3; i++) {
        if (b[i][0] == c && b[i][1] == c && b[i][2] == c) return true;
    }
    // cols
    for (int j = 0; j < 3; j++) {
        if (b[0][j] == c && b[1][j] == c && b[2][j] == c) return true;
    }
    // diagonals
    if (b[0][0] == c && b[1][1] == c && b[2][2] == c) return true;
    if (b[0][2] == c && b[1][1] == c && b[2][0] == c) return true;
    return false;
}

int solution(vector<string> board) {
    int oCnt = 0, xCnt = 0;
    for (auto &row : board) {
        for (char ch : row) {
            if (ch == 'O') oCnt++;
            else if (ch == 'X') xCnt++;
        }
    }

    // 1) count rule
    if (!(oCnt == xCnt || oCnt == xCnt + 1)) return 0;

    bool oWin = win(board, 'O');
    bool xWin = win(board, 'X');

    // 2) both win impossible
    if (oWin && xWin) return 0;

    // 3) winner vs count consistency
    if (oWin) {
        if (oCnt != xCnt + 1) return 0;
    }
    if (xWin) {
        if (oCnt != xCnt) return 0;
    }

    return 1;
}
