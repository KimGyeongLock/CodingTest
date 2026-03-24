#include <iostream>
#include <vector>


using namespace std;

int answer = 0;

vector<int> mergeLine(const vector<int>& line) {
    vector<int> nums;
    for (int x : line) {
        if (x != 0) nums.push_back(x);
    }

    vector<int> merged;
    for (int i = 0; i < nums.size(); i++) {
        if (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
            merged.push_back(nums[i] * 2);
            i++;
        } else {
            merged.push_back(nums[i]);
        }
    }

    return merged;
}

void moveBoard(int dir, int n, vector<vector<int>>& board) {

    if (dir == 0) { // 상
        for (int col = 0; col < n; col++) {
            vector<int> line;
            for (int row = 0; row < n; row++) {
                line.push_back(board[row][col]);
            }

            vector<int> merged = mergeLine(line);

            for (int row = 0; row < n; row++) {
                if (row < merged.size()) board[row][col] = merged[row];
                else board[row][col] = 0;
            }
        }
    } else if (dir == 1) { // 하 
        for (int col = 0; col < n; col++) {
            vector<int> line;
            for (int row = n - 1; row >= 0; row--) {
                line.push_back(board[row][col]);
            }

            vector<int> merged = mergeLine(line);

            for (int row = n - 1, idx = 0; row >= 0; row--, idx++) {
                if (idx < merged.size()) board[row][col] = merged[idx];
                else board[row][col] = 0;
            }
        }
    } else if (dir == 2) { // 좌
        for (int row = 0; row < n; row++) {
            vector<int> line;
            for (int col = 0; col < n; col++) {
                line.push_back(board[row][col]);
            }

            vector<int> merged = mergeLine(line);

            for (int col = 0; col < n; col++) {
                if (col < merged.size()) board[row][col] = merged[col];
                else board[row][col] = 0;
            }
        }
    } else { // 우
        for (int row = 0; row < n; row++) {
            vector<int> line;
            for (int col = n - 1; col >= 0; col--) {
                line.push_back(board[row][col]);
            }

            vector<int> merged = mergeLine(line);

            for (int col = n - 1, idx = 0; col >= 0; col--, idx++) {
                if (idx < merged.size()) board[row][col] = merged[idx];
                else board[row][col] = 0;
            }
        }
    }
}

void dfs(int idx, int n, vector<vector<int>>& board) {
    if (idx == 5) {
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++)
                answer = max(answer, board[i][j]);

        return;
    }

    for (int dir = 0; dir < 4; dir++) {
        vector<vector<int>> nextBoard = board;
        moveBoard(dir, n, nextBoard);
        dfs(idx + 1, n, nextBoard);
    }
}

int solution(int n, vector<vector<int>> board) {
    dfs(0, n, board);
    return answer;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<vector<int>> board(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << solution(N, board);
}