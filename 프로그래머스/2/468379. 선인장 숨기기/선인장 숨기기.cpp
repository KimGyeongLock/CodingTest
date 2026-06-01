#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int m, int n, int h, int w, vector<vector<int>> drops) {    
    int INF = drops.size() + 1;
    vector<vector<int>> board(m, vector<int>(n, INF));
    
    for (int i = 0; i < drops.size(); i++) {
        board[drops[i][0]][drops[i][1]] = i + 1;
    }
    
    int colCount = n - w + 1;
    vector<vector<int>> rowMin(m, vector<int>(colCount));
    
    for (int i = 0; i < m; i++) {
        deque<int> dq; // dq.front()는 항상 현재 구간의 최솟값 위치
        
        for (int j = 0; j < n; j++) {
            while (!dq.empty() && board[i][dq.back()] >= board[i][j]) {
                dq.pop_back(); 
                // 새로 들어온 것(board[i][j])이 기존에 있던 값(board[i][dq.back()])보다 크거나 같으면 기존 값 제거
            }
            dq.push_back(j);
            
            if (dq.front() <= j - w) {
                dq.pop_front();
            }
            
            if (j >= w - 1) { // w가 채워졌다
                rowMin[i][j - w + 1] = board[i][dq.front()];
            }
        }
    }
    
    int bestValue = -1;
    vector<int> answer = {0, 0};
    
    for (int j = 0; j < colCount; j++) {
        deque<int> dq;
        
        for (int i = 0; i < m; i++) {
            while(!dq.empty() && rowMin[dq.back()][j] >= rowMin[i][j]) {
                dq.pop_back();
            }
            
            dq.push_back(i);
            
            if (dq.front() <= i - h) {
                dq.pop_front();
            }
            
            if (i >= h - 1) {
                int value = rowMin[dq.front()][j];
                int top = i - h + 1;
                if (value > bestValue ||
                   (value == bestValue && (top < answer[0] || (top == answer[0] && j < answer[1])))) {
                    bestValue = value;
                    answer = {top, j};
                }
            }
            
        }
    }
    
    
    return answer;
}