#include <vector>
#include <string>
using namespace std;

int solution(vector<string> arr)
{
    int nNums = arr.size() / 2 + 1;
    vector<int> nums(nNums);
    vector<char> ops(nNums - 1);
    for (int i = 0; i < arr.size(); i += 2) {
        nums[i/2] = stoi(arr[i]);
        if (i + 1 < arr.size()) {
            ops[i/2] = arr[i+1][0];
        }
    }
    
    int n = nums.size();
    const int INF = 1e9;
    
    vector<vector<int>> minDP(n, vector<int>(n, INF));
    vector<vector<int>> maxDP(n, vector<int>(n, -INF));
    
    for (int i = 0; i < n; i++) {
        minDP[i][i] = nums[i];
        maxDP[i][i] = nums[i];
    }
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;
            
            
            for (int k = i; k < j; k++) { 
                char op = ops[k];
                
                if (op == '+') {
                    int candMax = maxDP[i][k] + maxDP[k+1][j];
                    int candMin = minDP[i][k] + minDP[k+1][j];
                    
                    maxDP[i][j] = max(maxDP[i][j], candMax);
                    minDP[i][j] = min(minDP[i][j], candMin);
                } else if (op == '-') {
                    int candMax = maxDP[i][k] - minDP[k+1][j];
                    int candMin = minDP[i][k] - maxDP[k+1][j];
                    
                    maxDP[i][j] = max(maxDP[i][j], candMax);
                    minDP[i][j] = min(minDP[i][j], candMin);
                }
            }
        }
    }
    
    return maxDP[0][n-1];
}