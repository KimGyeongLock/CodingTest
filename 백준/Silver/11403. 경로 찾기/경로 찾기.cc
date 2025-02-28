#include <iostream>

using namespace  std;
// 플로이드 알고리즘 : 모든 정점 쌍 사이의 최단거리를 구하는 알고리즘

int arr[100][100];

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 

    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        }
    }
    // 경유지 k에 대해 0~k
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (arr[i][k] && arr[k][j]) {
                    arr[i][j] = 1;
                }
            }
        }
    }
    // 결과 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}