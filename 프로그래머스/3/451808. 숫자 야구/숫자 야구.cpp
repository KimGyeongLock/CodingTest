#include <string>
#include <vector>
#include <climits>
#include <map>

using namespace std;

extern string submit(int);

int solution(int n) {
    vector<int> candidates;
    
    // 9P4 = 9 * 8 * 7 * 6 = 3024
    for (int a = 1; a <= 9; a++) {
        for (int b = 1; b <= 9; b++) {
            if (b == a) continue;
            for (int c = 1; c <= 9; c++) {
                if (c == a || c == b) continue;
                for (int d = 1; d <= 9; d++) {
                    if (d == a || d == b || d == c) continue;
                    
                    int num = a * 1000 + b * 100 + c * 10 + d;
                    candidates.push_back(num);
                }
            }
        }
    }
    
    auto getScore = [](int guess, int answer) {
        string g = to_string(guess);
        string a = to_string(answer);
        
        int strike = 0;
        int ball = 0;
        
        for (int i = 0; i < 4; i++) {
            if (g[i] == a[i]) {
                strike++;
            } else {
                for (int j = 0; j < 4; j++) {
                    if (g[i] == a[j]) {
                        ball++;
                        break;
                    }
                }
            }
        }
        
        return pair<int, int>{strike, ball};
    };
    
    while (candidates.size() > 1) {
        int bestGuess = candidates[0];
        int bestWorst = INT_MAX;
        
        for (int guess : candidates) {
            map<pair<int, int>, int> groupCount;
            
            for (int answer : candidates) {
                groupCount[getScore(guess, answer)]++;
            }
            
            int worst = 0;
            for (auto &p : groupCount) {
                worst = max(worst, p.second);
            }
            
            if (worst < bestWorst) {
                bestWorst = worst;
                bestGuess = guess;
            }
        }
        
        string result = submit(bestGuess);
        
        int strike = result[0] - '0';
        int ball = result[3] - '0';
        
        vector<int> nextCandidates;
        for (int answer : candidates) {
            if (getScore(bestGuess, answer) == make_pair(strike, ball)) {
                nextCandidates.push_back(answer);
            }
        }
        
        candidates = nextCandidates;
    }
    
    return candidates[0];
}