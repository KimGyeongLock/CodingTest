#include <iostream>

using namespace std;

int n[3], m[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<3;i++) {
        cin >> n[i] >> m[i];
    }
    int dx1 = n[1] - n[0];
    int dy1 = m[1] - m[0];
    int dx2 = n[2] - n[0];
    int dy2 = m[2] - m[0];

    int crossProduct = dx1 * dy2 - dx2 * dy1;

    if(crossProduct > 0) {
        cout << "1" << endl;
    } else if(crossProduct < 0) {
        cout << "-1" << endl;
    } else {
        cout << "0" << endl;
    }

    return 0;
}
