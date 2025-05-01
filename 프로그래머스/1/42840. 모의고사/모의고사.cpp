#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    vector<int> su1 = {1, 2, 3, 4, 5};
    vector<int> su2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> su3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    vector<vector<int>> su = {su1, su2, su3};
    
    vector<int> a(3);
    for(int j = 0; j < 3; j++) {
        for(int i = 0; i < answers.size(); i++) {
            if(answers[i] == su[j][i % su[j].size()]) {
                a[j]++;
            }
        }
    }
    
    int max_val = *max_element(a.begin(), a.end());
    for(int i = 0; i < a.size(); i++) {
        if (max_val == a[i]) {
             answer.push_back(i + 1);
        }
    }
    
    return answer;
}