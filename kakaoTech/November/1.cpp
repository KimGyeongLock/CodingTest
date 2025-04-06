#include <iostream>
// #include <vector>
#include <set>
#include <algorithm>

using namespace std;

set<string> A, B;

// vector<string> A, B;

// bool find(vector<string> vec, string str) {
//     for(int i = 0; i < vec.size(); i++) {
//         if (str == vec[i]) {
//             return true;
//         }
//     }
//     return false;
// }

// void remove(vector<string>& vec, string str) {
//     for(int i = 0; i < vec.size(); i++) {
//         if (str == vec[i]) {
//             vec.erase(vec.begin() + i);
//             break;
//         }
//     }
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        // A.push_back(a);
        A.insert(a);
    }
    for(int i = 0; i < N; i++) {
        string a;
        cin >> a;
        // B.push_back(a);
        B.insert(a);
    }

    for(int i = 0; i < M; i++) {
        string a, b;
        cin >> a >> b;
        if(A.count(a) && B.count(b)) {
            A.erase(a);
            B.erase(b);
            A.insert(b);
            B.insert(a);
        }
        // if (find(A, a) && find(B, b)) {
        //     remove(A, a);
        //     remove(B, b);
        //     A.push_back(b);
        //     B.push_back(a);
        // }
    }

    // sort(A.begin(), A.end());

    for(string s : A) {
        cout << s << " ";
    }
}
