#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<bool> checked;

int check(vector<int>& cards, int idx, int cnt) {
    if (checked[idx-1]) {
        return cnt;
    }
    checked[idx-1] = true;
    return check(cards, cards[idx-1], cnt+1);
}

int solution(vector<int> cards) {
    int answer = 0;
    
    int n = cards.size();
    vector<int> v;
    checked.assign(n, false);
    for (int i = 0; i < n; i++) {
        if (checked[i]) continue;
        int total = check(cards, cards[i], 0);
        v.push_back(total);
    }
    
    sort(v.begin(), v.end(), greater<>());
    if (v.size() == 1) return 0;
    return v[0]*v[1];
}