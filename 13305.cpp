#include <iostream>
#include <vector>

using namespace std;

vector<int> road;
vector<int> oil;

int main()
{
    /*
        N개의 도시
        일직선 도로 위
        두 도시 사이의 도로의 길이는 다를 수 있다. (1이상 1,000,000,000 이하의 자연수)
        1km - 1L
        각 도시에는 하나의 주유소
        주유소 리터당 가격이 다르다. (1 이상 1,000,000,000 이하)
        최소 비용
    */
    int N;
    cin >> N;

    road.resize(N-1);
    oil.resize(N);
    
    int finishLength = 0;
    for(int i=0;i<N-1;i++) {
        cin >> road[i];
        finishLength += road[i];
    }
    for(int i=0;i<N;i++) {
        cin >> oil[i];
    }

    long sum = 0;
    long min_price = oil[0];

    for(int i=0;i<N-1;i++) {
        if(oil[i] < min_price) {
            min_price = oil[i];
        }
        sum += min_price * road[i];
    }

    cout << sum;
}