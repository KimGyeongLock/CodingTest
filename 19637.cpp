#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() 
{
    int N, M;
    cin >> N >> M;
    vector<string> style(N);
    vector<int> power(N);
    vector<int> characters(M);
    map<int, string> m;

    for(int i = 0; i < N; i++) {
        cin >> style[i] >> power[i];
    }

    for(int i = 0; i < M; i++) {
        cin >> characters[i];
    }
    vector<int> newCharacters(M);
    newCharacters = characters;

    sort(newCharacters.begin(), newCharacters.end());

    int i = 0;
    int j = 0;
    for(int j=0;j<M;j++) {
        if(power[i] < newCharacters[j]) {
            i++;
            j--;
        } else {
            m[newCharacters[j]] = style[i];
        }
    }
    // m의 내용을 출력
    for(int j=0;j<M;j++) {
        cout << m[characters[j]] << "\n";
    }
    // for(const auto &entry : m) {
    //     cout << "Power: " << entry.first << ", Style: " << entry.second << endl;
    // }
}

// int main()
// {
//     int N, M;
//     cin.tie(0); ios::sync_with_stdio(0);
//     cin >> N >> M;
//     vector<string> style(N);
//     vector<int> power(N);

//     for (int i = 0; i < N; i++) {
//         cin >> style[i] >> power[i];
//     }

//     int characters;
//     for (int i = 0; i < M; i++) {
//         cin >> characters;
        
//         auto upper = upper_bound(power.begin(), power.end(), characters-1); //characters-1 : characters 포함
//         int index = distance(power.begin(), upper);

//         cout << style[index] << "\n";
//     }

//     return 0;
// }