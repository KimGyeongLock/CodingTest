#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    unordered_map<string, int> map;
    for(vector<string> cloth : clothes) {
        map[cloth[1]]++;
    }
    
    int sum = 1;
    for(auto m : map) {
        sum *= (m.second + 1);
    }
    return sum - 1;
}