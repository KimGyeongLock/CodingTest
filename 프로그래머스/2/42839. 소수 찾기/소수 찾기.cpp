#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for(int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    set<int> candidates;
    sort(numbers.begin(), numbers.end());
    do {
        for(int len = 1; len <= numbers.size(); len++) {
            int num = stoi(numbers.substr(0, len));
            candidates.insert(num);
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    for(int i : candidates) {
        if (isPrime(i)) {
            answer++;
        }
    }
    return answer;
}