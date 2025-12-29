#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> scores) {
    int wa = scores[0][0];
    int wb = scores[0][1];
    int wsum = wa + wb;

    // (a desc, b asc)
    sort(scores.begin(), scores.end(), [](const vector<int>& x, const vector<int>& y) {
        if (x[0] != y[0]) return x[0] > y[0];
        return x[1] < y[1];
    });

    int maxB = -1;
    int rank = 1; // 완호 기본 석차

    for (auto &s : scores) {
        int a = s[0], b = s[1];

        // 지배(탈락) 판정: 앞에 a가 더 큰(또는 같은) 사람이 있고, b도 더 큰 사람이 존재하는 상황
        // 정렬 덕분에 b < maxB면 "a가 더 큰 사람이면서 b도 더 큰" 케이스가 성립
        if (b < maxB) {
            // 완호가 탈락이면 -1
            if (a == wa && b == wb) return -1;
            continue; // 탈락자는 석차 계산에서 제외
        }

        // 탈락이 아니면 maxB 갱신
        maxB = max(maxB, b);

        // 완호보다 합이 큰 인센티브 대상자 수 카운트
        if (a + b > wsum) rank++;
    }

    return rank;
}
