#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    vector<int> arr(n+1, 0);
    
    for (int i = 1; i <= n; i++) {
        arr[i] = arr[i-1] + sequence[i-1];
    }
    
    auto binary_search = [&] (const int x) {
        int left = 1, right = n;
        while(left <= right) {
            int mid = (left + right) / 2;
            if (arr[mid] == x) {
                return mid;
            } else if (arr[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    };
    
    vector<int> result;
    int min_length = n+1;
    for (int i = 1; i <= n; i++) {
        int res = binary_search(k + arr[i-1]);
        if (res) {
            int len = res - i;
            if (min_length > len) {
                min_length = len;
                result = {i-1, res-1};
            }
        }
    }
    return result;
}