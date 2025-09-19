#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    int R = 0, T = 0, C = 0, F = 0, J = 0, M = 0, A = 0, N = 0;
    unordered_map<char, int> map;
    
    for (int i = 0; i < choices.size(); i++) {
        if (choices[i] <= 3) {
            map[survey[i][0]] += 4 - choices[i];
        } else if (choices[i] >= 5) {
            map[survey[i][1]] += choices[i] - 4;
        }
    }
    
    auto choose = [&](int a, int b, char ca, char cb) {
        if (a > b) answer.push_back(ca);
        else if (a < b) answer.push_back(cb);
        else if (a == b) {
            if (ca > cb) {
                answer.push_back(cb);
            } else {
                answer.push_back(ca);
            }
        }
    };
    
    choose(map['R'], map['T'], 'R', 'T');
    choose(map['C'], map['F'], 'C', 'F');
    choose(map['J'], map['M'], 'J', 'M');
    choose(map['A'], map['N'], 'A', 'N');
    return answer;
}