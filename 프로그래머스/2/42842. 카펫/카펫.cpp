#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int total = brown + yellow;

    for(int w = 3; w <= total; w++) {
        int h = total / w;
        if (total % h == 0 && (w - 2) * (h - 2) == yellow) {
            answer[0] = max(w, h);
            answer[1] = min(w, h);
            break;
        }
    }
    return answer;
}