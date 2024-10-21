#include<iostream>
#include<vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N,M;
    cin >> N >> M;

    vector<vector<int> > v(N+1, vector<int>(N+1, 0));

    for(int i=1;i<N+1;i++) {
        for(int j=1;j<N+1;j++) {
            int value;
            cin >> value;
            v[i][j] = v[i][j-1] + v[i-1][j] + value - v[i-1][j-1];
        }
    }

    for(int i=0;i<M;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << v[x2][y2] - v[x2][y1-1] - v[x1-1][y2] + v[x1-1][y1-1] << "\n";
    }
}