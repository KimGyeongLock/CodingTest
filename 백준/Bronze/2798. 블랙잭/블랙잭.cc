#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int n, m;
int result = 0;

void b(int start, int count, int sum) {
    if (sum > m) return;

    if(count == 3) {
        result = max(result, sum);
        return;
    }

    for(int i = start; i < n; i++) {
        b(i + 1, count + 1, sum + v[i]);
    }
}

int main()
{
    /*
        N장의 카드 중에서 3장의 카드를 고른다.
        고른 카드의 합은 M을 넘지 않고 M과 최대한 가깝게

        브루트포스 => 노가다 => 모든 경우의 수 => 재귀
    */

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    v.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }

    b(0, 0, 0);

    cout << result;
}