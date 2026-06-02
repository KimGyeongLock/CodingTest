#include <string>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {
    vector<vector<int>> board(m, vector<int>(n, INT_MAX));
    for (int i = 0; i < drops.size(); i++) {
        board[drops[i][0]][drops[i][1]] = i + 1;
    }
    
    int colCount = n - w + 1;
    vector<vector<int>> rowMin(m, vector<int>(colCount, INT_MAX));
    for (int i = 0; i < m; i++) {
        deque<int> dq;
        for (int j = 0; j < n; j++) {
            while (!dq.empty() && board[i][dq.back()] >= board[i][j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            if (dq.front() <= j - w) {
                dq.pop_front();
            }
            if (j >= w - 1) {
                rowMin[i][j - w + 1] = board[i][dq.front()];
            }
        }
    }
    
    vector<int> answer = {0, 0};
    int bestValue = -1;
    for (int j = 0; j < colCount; j++) {
        deque<int> dq;
        for (int i = 0; i < m; i++) {
            while (!dq.empty() && rowMin[dq.back()][j] >= rowMin[i][j]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if (dq.front() <= i - h) {
                dq.pop_front();
            }
            if (i >= h - 1) {
                int top = i - h + 1;
                int value = rowMin[dq.front()][j];
                if (bestValue < value ||
                    bestValue == value && (top < answer[0] || (top == answer[0] && j < answer[1]))) {
                    bestValue = value;
                    answer = {top, j};
                }
            }
        }
    }
    return answer;
}