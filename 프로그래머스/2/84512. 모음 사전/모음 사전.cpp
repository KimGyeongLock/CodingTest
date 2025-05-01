#include <string>
#include <vector>

using namespace std;

int answer = 0;
int count = 0;

void dfs(string word, string target, string current) {
    if (current == target) {
        answer = count;
    }
    
    if (current.length() >= 5) return;
    
    for(int i = 0; i < word.length(); i++) {
        count++;
        dfs(word, target, current + word[i]);
        if (answer != 0) return;
    }
}

int solution(string word) {
    string aeious = "AEIOU";
    dfs(aeious, word, "");
    return answer;
}