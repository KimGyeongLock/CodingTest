#include <iostream>
#include <algorithm>


using namespace std;

int main() {
    string s;
    cin >> s;

    /*
    aabbaaabaaba , (n = 12)
    a를 연속으로 한다 = b를 연속으로 한다.
    최솟값 -> 그리디 or 모든 경우의 수를 구하고 그 중 최솟값

    a의 갯수만큼 연속되어야 한다 -> 8개
    aaaaaaaabbbb 이렇게 만들어야 한다.

    모든 경우는 똑같다. 하지만 어떻게 묶어야 교체 횟수가 적은지 찾는다.
    [aabbaaab]aaba -> 3개 교체
    [abbaaaba]abaa -> 3개 교체
    [bbaaabaa]baaa -> 3개 교체
    [baaabaab]aaab -> 3개 교체
    [aaabaaba]aabb -> 2개 교체
    [aabaabaa]abba -> 2개 교체
    [abaabaaa]bbaa -> 2개 교체
    [baabaaab]baaa -> 3개 교체
    [aabaaabb]aaab -> 3개 교체
    [abaaabba]aaba -> 3개 교체
    [baaabbaa]abaa -> 3개 교체
    [aaabbaaa]baab -> 2개 교체
    = 12번 (n)
    -> 최소 2번 교체가 필요
    */

    // a 의 개수 구하기
    int aCount = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == 'a') aCount++;
    }

    cout << s.substr(2, -3) << "\n";


    string window;
    int min_value = 1001;
    for(int i = 0; i < s.length(); i++) {
        if(i + aCount > s.length()) {
            window = s.substr(i);
            window += s.substr(0,  (i + aCount) - s.length());
        } else {
            window = s.substr(i, aCount); // 0 ~ 8 -> 1 ~ 8
        }        
        int result = count(window.begin(), window.end(), 'b'); // 문자열 길이 최대 1,000 -> 2중 포문 -> 1000*1000 = 1000000 (가능)
        min_value = min(min_value, result);
    }

   cout << min_value;
}