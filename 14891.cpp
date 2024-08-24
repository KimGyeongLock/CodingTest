#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vec(4, vector<int>(8));
vector<int> num;
vector<int> dir;

void clockwise(int number) {
    int temp = vec[number-1][7];
    for(int i=6;i>=0;i--) {
        vec[number-1][i+1] = vec[number-1][i];

    }
    vec[number-1][0] = temp;
}

void anticlockwise(int number) {
    int temp = vec[number-1][0];
    for(int i=1;i<8;i++) {
        vec[number-1][i-1] = vec[number-1][i];
    }
    vec[number-1][7] = temp;
}

void rightTurn(int number, int direction) {
    if(number < 4 && vec[number-1][2] != vec[number][6]) {
        rightTurn(number+1 , direction * -1);
    }
    if(direction == 1) clockwise(number);
    else anticlockwise(number);
}

void leftTurn(int number, int direction) {
    if(number-2 >= 0 && vec[number-1][6] != vec[number-2][2]){
        leftTurn(number-1 , direction * -1);
    }
    if(direction == 1) clockwise(number);
    else anticlockwise(number);
}

void func(int number, int direction) {
    if(direction == 1) { //시계방향
        if(number < 4 && vec[number-1][2] != vec[number][6]) {
            rightTurn(number+1 , direction * -1);
        }

        if(number-2 >= 0 && vec[number-1][6] != vec[number-2][2]){
            leftTurn(number-1 , direction * -1);
        }
        //number - 시계방향으로 회전 11시 있던게 -> 12시
        clockwise(number);
    } else if(direction == -1) { //반시계방향
        if(number < 4 && vec[number-1][2] != vec[number][6]) {
            rightTurn(number+1 , direction * -1);
        }

        if(number-2 >= 0 && vec[number-1][6] != vec[number-2][2]){
            leftTurn(number-1 , direction * -1);
        }
        //number - 반시계방향으로 회전 11시 있던게 -> 12시
        anticlockwise(number);
    }
}

int main()
{
    /*
        톱니바퀴, N(0), S(1);
        맞닿은 톱니의 극이 다르다면, B는 A가 회전한 반대방향으로 회전

        맞닿는 톱니 3번째 - 7번째
    */

    for(int i=0;i<4;i++) {
        string s;
        cin >> s;
        for(int j=0;j<8;j++) {
            vec[i][j] = s[j] - '0';
        }
    }
    int K;
    cin >> K;
    num.resize(K);
    dir.resize(K);

    for(int i=0;i<K;i++) {
        cin >> num[i] >> dir[i];
    }

    for(int i=0;i<K;i++) {
        func(num[i], dir[i]);
    }
    int sum = 0;
    
    if(vec[0][0] == 1) sum += 1;
    if(vec[1][0] == 1) sum += 2;
    if(vec[2][0] == 1) sum += 4;
    if(vec[3][0] == 1) sum += 8;
    
    cout << sum;
}
