#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(int N, int number) {
    vector<unordered_set<int>> vec(9);
    
    int repeated = 0;
    for (int i = 1; i < 9; i++) {
        repeated = repeated * 10 + N;
        vec[i].insert(repeated);
        
        for (int j = 1; j < i; j++) {
            for (int a : vec[j]) {
                for (int b : vec[i-j]) {
                    vec[i].insert(a+b);
                    vec[i].insert(a-b);
                    vec[i].insert(b-a);
                    vec[i].insert(a*b);
                    if(b!=0) vec[i].insert(a/b);
                    if(a!=0) vec[i].insert(b/a);
                }
            }
        }
        if (vec[i].count(number)) return i;
    }
    
    
    return -1;
}