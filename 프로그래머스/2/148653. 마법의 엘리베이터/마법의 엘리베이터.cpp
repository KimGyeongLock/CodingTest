#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0) {
        int d = storey % 10;
        int next = (storey / 10) % 10;
        
        if (d > 5) {
            answer += 10 - d;
            storey = storey / 10 + 1;
        } else if (d < 5) {
            answer += d;
            storey = storey / 10;
        } else {
            if (next >= 5) {
                answer += 5;
                storey = storey / 10 + 1;
            } else {
                answer += 5;
                storey = storey / 10;
            }
        }
    }
    
    return answer;
}