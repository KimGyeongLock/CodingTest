#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> height;
vector<int> numberOfLeft;
vector<int> closeLeftBuilding;
vector<int> numberOfRight;
vector<int> closeRightBuilding;

void leftBuilding() {

    stack<int> st;
    for(int i = 0;i < N;i++) {

        while (!st.empty() && height[st.top()] <= height[i]) { // 8 5(X) 4(X) 3(X) 7 => while
            st.pop();
        }

        if(!st.empty()){
            numberOfLeft[i] = numberOfLeft[st.top()] + 1;
            closeLeftBuilding[i] = st.top() + 1;
        }

        st.push(i);
    }
}

void rightBuilding() {
    stack<int> st;
    for(int i = N - 1;i >= 0;i--) {

        while (!st.empty() && height[st.top()] <= height[i]) {
            st.pop();
        }

        if(!st.empty()){
            numberOfRight[i] = numberOfRight[st.top()] + 1;
            closeRightBuilding[i] = st.top() + 1;
        }

        st.push(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    /*
    
        건물 N개
        현재 있는 건물의 높이보다 큰 건물만 볼 수 있다.

        i 번째 건물에서 볼 수 있는 건물의 개수
        볼 수 있는 건물의 개수가 1개 이상이면 가장 가까운 건물, 같을 경우 작은 번호
    
        n <= 100,000 n^2 불가능

        투포인터?, 
        이진탐색? => 정렬 필요, 순서가 있는 문제이기 때문에 정렬은 불 필요X

        스택 => 앞에 있는 건물들을 그대로 쌓되 건물의 높이보다 낮으면 쌓지 않는다.
        // pop은 현재 건물보다 낮은 건물
        // 스택 : 0(3): 없음
        // 스택 : 1(7): 3(pop) -> 없음
        // 스택 : 2(1): 7(top)
        // 스택 : 3(6): 7 1(pop) -> 7(top)
        // 스택 : 4(3): 7 6(top)
        // 스택 : 5(5): 7 6 3(pop) -> 7 6(top)
        // 스택 : 6(1): 7 6 5(top)
        // 스택 : 7(7): 7 6 5 1(pop) -> 7 6 5(top)
        // push 7(X) 6(X) 5(X) 7 => 7 (1개)
        // 항상 push, 현재 건물보다 낮은 건물 pop
        // 가장 가깝고 높은 건물 = top
        // pop이 아니라면 top의 개수에 + 1
     */

    cin >> N;

    height.resize(N);
    numberOfLeft.resize(N, 0);
    closeLeftBuilding.resize(N, 0);
    numberOfRight.resize(N, 0);
    closeRightBuilding.resize(N, 0);
    for(int i = 0;i < N;i++) {
        cin >> height[i];
    }

    leftBuilding();
    rightBuilding();

    for(int i = 0;i < N;i++) {
        int totalBuilding = numberOfLeft[i] + numberOfRight[i];
        int mostClosestBuilding = 0;

        if (numberOfRight[i] != 0 && numberOfLeft[i] != 0) {
            if(abs(closeLeftBuilding[i] - (i+1)) <= abs(closeRightBuilding[i] - (i+1))) { // 같을 경우 right보다 left 숫자가 작은
                mostClosestBuilding = closeLeftBuilding[i];
            } else {
                mostClosestBuilding = closeRightBuilding[i];
            }
        } else if (numberOfRight[i] == 0) {
            mostClosestBuilding = closeLeftBuilding[i];
        } else if (numberOfLeft[i] == 0) {
            mostClosestBuilding = closeRightBuilding[i];
        }

        if(totalBuilding == 0) {
            cout << 0 << "\n";
        } else {
            cout << totalBuilding << " " << mostClosestBuilding << "\n";
        }
    }

    
}