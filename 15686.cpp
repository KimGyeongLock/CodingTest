#include <iostream>
#include <vector>
#include <cmath> // abs
#include <algorithm> // min
#include <climits> // INT_MAX


using namespace std;

int N, M;
vector<pair<int, int> > home;
vector<pair<int, int> > chicken;

vector<vector<pair<int, int> > > combinations;

void combination(vector<pair<int, int> >& current, int start, int K) {
    if(current.size() == K) {
        combinations.push_back(current);
        return;
    }

    for(int i=start;i<chicken.size();i++) {
        current.push_back(chicken[i]);
        combination(current, i+1, K);
        current.pop_back();
    }
}

int calcul(vector<pair<int, int> >& current) {
    int total = 0;
    for(int i=0;i<home.size();i++) {
        int min_v = INT_MAX;
        for(int j=0;j<current.size();j++) {
            // cout << current[j].first << ", " << current[j].second << "\n";
            min_v = min(abs(home[i].first-current[j].first) + abs(home[i].second-current[j].second), min_v);
        }
        total += min_v;
    }
    return total;
}

int main()
{
    cin >> N >> M;
    vector<vector<int> > S(N, vector<int>(N));

    
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> S[i][j];
            if(S[i][j] == 1) {
                pair<int, int> a;
                a = make_pair(i, j);
                home.push_back(a);
            } else if(S[i][j] == 2) {
                pair<int, int> a;
                a = make_pair(i, j);
                chicken.push_back(a);
            }
        }
    }

    vector<pair<int, int> > backtracking;
    for(int i=1;i<=M;i++) {
        combination(backtracking, 0, i);
    }

    int result = INT_MAX;
    for(int i=0;i<combinations.size();i++) {
        result = min(calcul(combinations[i]), result);
    }
    cout << result;
}