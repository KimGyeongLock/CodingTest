#include <vector>
#include <unordered_set>
using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> s;
    for(int n : nums) {
        s.insert(n);
    }
    
    return min(s.size(), nums.size() / 2);
}