#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> u;
    for(string c : completion) {
        u[c]++;
    }
    
    for(string p : participant) {
        if(u[p] == 0) {
            return p;
        }
        u[p]--;
    }
    return "";
}