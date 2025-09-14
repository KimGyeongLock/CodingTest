#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

static void makeSums(const vector<vector<int>>& dices, int idx, int cur, vector<int>& out) {
    if (idx == dices.size()) {
        out.push_back(cur); return;
    }
    for (int x : dices[idx]) {
        makeSums(dices, idx + 1, cur + x, out);
    }
}

vector<int> solution(vector<vector<int>> dice) {
    int n = dice.size();
    int half = n / 2;
    
    vector<int> best;
    long long bestWins = -1;
    
    vector<int> pick(n, 0);
    fill(pick.end() - half, pick.end(), 1);
    do {
        vector<vector<int>> A, B;
        A.reserve(half); B.reserve(half);
        for (int i = 0; i < n; i++) {
            if (pick[i]) A.push_back(dice[i]);
            else B.push_back(dice[i]);
        }
        
        vector<int> SA, SB;
        SA.reserve(pow(6, half) + 1); // 모든 합 구하기 (경우의수 6^(n/2))
        SB.reserve(pow(6, half) + 1);
        makeSums(A, 0, 0, SA);
        makeSums(B, 0, 0, SB);
        sort(SB.begin(), SB.end());
        
        long long wins = 0;
        for (int s : SA) {
            wins += upper_bound(SB.begin(), SB.end(), s - 1) - SB.begin();
        }
        
        if (wins > bestWins) {
            bestWins = wins;
            best.clear();
            for (int i = 0; i < n; i++) {
                if (pick[i]) best.push_back(i + 1);
            }
        } 
    } while(next_permutation(pick.begin(), pick.end()));
    return best;
}