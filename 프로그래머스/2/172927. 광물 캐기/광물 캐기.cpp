#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    
    vector<array<int, 3>> score;
    array<int, 3> val = {0, 0, 0};
    int total = picks[0] + picks[1] + picks[2];
    int maxM = min((int)minerals.size(), total * 5);

    for (int i = 0; i < maxM + 1; i++) {
        if ((i % 5 == 0 && i != 0) || i == maxM) {
            
            score.push_back(val);
            val = {0, 0, 0};

            if (i == maxM) break;
        }
        if (minerals[i] == "diamond") val[0] += 1;
        if (minerals[i] == "iron") val[0] += 1;
        if (minerals[i] == "stone") val[0] += 1;
        
        if (minerals[i] == "diamond") val[1] += 5;
        if (minerals[i] == "iron") val[1] += 1;
        if (minerals[i] == "stone") val[1] += 1;
        
        if (minerals[i] == "diamond") val[2] += 25;
        if (minerals[i] == "iron") val[2] += 5;
        if (minerals[i] == "stone") val[2] += 1;
    }
    
    sort(score.begin(), score.end(), [&] (const auto &a, const auto &b) {
        return a[2] > b[2];
    });
    
    int select = 0;
    for (int i = 0; i < score.size(); i++) {
        while (picks[select] <= 0) {
            select++;
        }
        if (select >= 3) break;
        answer += score[i][select];
        picks[select]--;
    }
    return answer;
}