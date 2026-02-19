#include <string>
#include <vector>

using namespace std;

vector<int> solution(int target) {
    int INF = 1e9;
    vector<pair<int, int>> dp(target + 1, {INF, INF}); // dp[i] = {minThrows, singleBool};
    dp[0] = {0, 0};
    
    vector<pair<int, int>> opts; // (score, signleBools)
    opts.push_back({50, 1});
    for (int i = 1; i <= 20; i++) {
        opts.push_back({i, 1});
        opts.push_back({2 * i, 0});
        opts.push_back({3 * i, 0});
    }
    
    auto better = [&](pair<int, int> a, pair<int, int> b) {
        if (a.first != b.first) return a.first < b.first;
        else return a.second > b.second;
    };
    
    for (int i = 1; i <= target; i++) {
        for (auto [sc, sb] : opts) {
            if (i - sc < 0) continue;
            if (dp[i - sc].first == INF) continue;
            
            pair<int, int> cand = {
                dp[i - sc].first + 1,
                dp[i - sc].second + sb
            };
            
            if (better(cand, dp[i])) dp[i] = cand;
        }
    }
    
    return {dp[target].first, dp[target].second};
}