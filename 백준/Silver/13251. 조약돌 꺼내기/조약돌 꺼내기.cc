#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M, K;
    cin >> M;
    vector<int> color(M);
    int counts = 0;
    for(int i = 0; i < M; i++) {
        cin >> color[i];
        counts += color[i];
    }
    cin >> K; 

    double sum = 0;
    for(int i = 0; i < M; i++) {
        double result = 1.0;
        for(int j = 0; j < K; j++) {
            result *= (double)(color[i] - j) / (counts - j);
        }
        sum += result;
    }

    cout << fixed;
    cout.precision(9);
    cout << sum;
}