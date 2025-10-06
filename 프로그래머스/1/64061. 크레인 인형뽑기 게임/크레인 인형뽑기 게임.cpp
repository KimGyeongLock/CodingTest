#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> st;
    int n = board.size();
    
    for (int m : moves) {
        for (int i = 0; i < n; i++) {
            if (board[i][m - 1] > 0) {
                if (!st.empty() && st.top() == board[i][m - 1]) {
                    answer += 2;
                    st.pop();
                } else st.push(board[i][m - 1]);
                board[i][m - 1] = 0;
                break;
            }
        }
        
    }
    return answer;
}