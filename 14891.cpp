#include <iostream>
#include <vector>

using namespace std;

vector<vector<int> > vec(4, vector<int>(8));
vector<int> num;
vector<int> dir;

void rightTurn(int number, int direction) {
    if(direction == 1) {
        if(number < 4 && vec[number-1][2] == vec[number][6]) { 

        } else {

        }
    } else {
        
    }
}

void leftTurn() {

}

void func(int number, int direction) {
    if(direction == 1) { //시계방향
    
        if(number < 4 && vec[number-1][2] == vec[number][6]) { //오른쪽 맞닿은 극이 같을 때
            //stop
        } else {
            //반시계방향으로 회전
            func(number+1 , -1);
            
            //number+1 - 반시계방향으로 회전
            int temp = vec[number][0];
            for(int i=1;i<8;i++) {
                vec[number][i-1] = vec[number][i];
            }
            vec[number][7] = temp;
        }

        if(number-2 >= 0 && vec[number-1][6] == vec[number-2][2]) { //왼쪽 맞닿은 극이 같을 때
            //stop
        } else {
            //시계방향으로 회전
            func(number-1 , 1);

            int temp = vec[number-2][7];
            for(int i=0;i<7;i++) {
                vec[number-2][i+1] = vec[number-2][i];
            }
            vec[number-2][0] = temp;
        }

        //number - 시계방향으로 회전 11시 있던게 -> 12시
        int temp = vec[number-1][7];
        for(int i=0;i<7;i++) {
            vec[number-1][i+1] = vec[number-1][i];
        }
        vec[number-1][0] = temp;
    } else if(direction == -1) { //반시계방향
        if(number < 4 && vec[number-1][2] == vec[number][6]) { //오른쪽 맞닿은 극이 같을 때
            //stop
        } else {
            //시계방향으로 회전
            func(number+1 , 1);
            
            //number+1 - 시계방향으로 회전
            int temp = vec[number][7];
            for(int i=0;i<7;i++) {
                vec[number][i+1] = vec[number][i];
            }
            vec[number][0] = temp;
        }

        if(number-2 >= 0 && vec[number-1][6] == vec[number-2][2]) { //왼쪽 맞닿은 극이 같을 때
            //stop
        } else {
            //반시계방향으로 회전
            func(number-1 , -1);

            int temp = vec[number-2][0];
            for(int i=1;i<8;i++) {
                vec[number-2][i-1] = vec[number-2][i];
            }
            vec[number-2][7] = temp;
        }

        //number - 반시계방향으로 회전 11시 있던게 -> 12시
        int temp = vec[number-1][0];
        for(int i=1;i<8;i++) {
            vec[number-1][i-1] = vec[number-1][i];
        }
        vec[number-1][7] = temp;
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
        for(int j=0;j<8;j++)
            cin >> vec[i][j];
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
    for(int i=0;i<4;i++) {
        if(vec[0][0] == 1) sum += 1;
        if(vec[1][0] == 1) sum += 2;
        if(vec[2][0] == 1) sum += 4;
        if(vec[3][0] == 1) sum += 8;
    }
    cout << sum;
}
