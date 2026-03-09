#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<pair<long long, long long>> stars;

    long long minX = 4e18, minY = 4e18;
    long long maxX = -4e18, maxY = -4e18;

    int n = line.size();

    for (int i = 0; i < n; i++) {
        long long A = line[i][0];
        long long B = line[i][1];
        long long E = line[i][2];

        for (int j = i + 1; j < n; j++) {
            long long C = line[j][0];
            long long D = line[j][1];
            long long F = line[j][2];

            long long denom = A * D - B * C;
            if (denom == 0) continue; // 평행 또는 일치

            long long xNumer = B * F - E * D;
            long long yNumer = E * C - A * F;

            // 정수 좌표가 아니면 제외
            if (xNumer % denom != 0 || yNumer % denom != 0) continue;

            long long x = xNumer / denom;
            long long y = yNumer / denom;

            stars.push_back({x, y});

            minX = min(minX, x);
            maxX = max(maxX, x);
            minY = min(minY, y);
            maxY = max(maxY, y);
        }
    }

    int width = (int)(maxX - minX + 1);
    int height = (int)(maxY - minY + 1);

    vector<string> answer(height, string(width, '.'));

    for (auto &p : stars) {
        long long x = p.first;
        long long y = p.second;

        int row = (int)(maxY - y);
        int col = (int)(x - minX);

        answer[row][col] = '*';
    }

    return answer;
}