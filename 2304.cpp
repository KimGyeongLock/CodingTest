#include<iostream>
#include<vector>
#include<map>

using namespace std;

map<int, int> LH;
int origin_extent = 0;
int max_H = 0;
int min_L = 1001;
int max_L = 0;

void leftBox(int max_H_index, int second_max_H) {
    int left_second_H = 0;
    int left_second_L = 0;
    for (auto it = LH.begin(); it != LH.end() && it->first != max_H_index; it++) {
        if(left_second_H < it->second) {
            left_second_H = it->second;
            left_second_L = it->first;
        }
    }
    origin_extent -= (second_max_H - left_second_H) * (max_H_index - min_L);

    if(left_second_L != min_L) {
        leftBox(left_second_L, left_second_H);
    }
}

void rightBox(int max_H_index, int second_max_H) {
    int right_second_H = 0;
    int right_second_L = 0;
    for (auto it = LH.begin(); it != LH.end(); it++) {
        if(it->first > max_H_index) {
            if(right_second_H < it->second) {
                right_second_H = it->second;
                right_second_L = it->first;
            }
        }
    }
    origin_extent -= (second_max_H - right_second_H) * ((max_L + 1) - (max_H_index + 1));

    if(right_second_L != max_L) {
        rightBox(right_second_L, right_second_H);
    }
}

int main()
{
    /*
        n개의 막대 기둥
        창고 다각형의 면적이 가장 작은 
        // 톱니바퀴 문제
    */

    int N;
    cin >> N; //1 이상 1000이하

    int max_H_index = 0;
    int L, H;
    for(int i=0;i<N;i++) {
        cin >> L >> H;
        LH[L] = H;
        if(max_L < L) {
            max_L = L;
        }
        if(min_L > L) {
            min_L = L;
        }
        if(max_H <= H) {
            max_H = H;
            max_H_index = L;
        }
    }
    int bottom = (max_L+1) - min_L;
    origin_extent = bottom * max_H; 

    int left_second_H = 0;
    int left_second_L = 0;
    int right_second_H = 0;
    int right_second_L = 0;
    if(max_H_index != min_L) {
        // 왼쪽
        for (auto it = LH.begin(); it != LH.end() && it->first != max_H_index; it++) {
            if(left_second_H <= it->second) {
                left_second_H = it->second;
                left_second_L = it->first;
            }
        }
        origin_extent -= (max_H - left_second_H) * (max_H_index - min_L); 
        if(left_second_L != min_L) {
            leftBox(left_second_L, left_second_H); //왼쪽으로
        }
    }
    if(max_H_index != max_L) {
        // 오른쪽
        for (auto it = LH.begin(); it != LH.end(); it++) {
            if(it->first >= max_H_index) {
                if(right_second_H < it->second) {
                    right_second_H = it->second;
                    right_second_L = it->first;
                }
            }
        }
        origin_extent -= (max_H - right_second_H) * ((max_L + 1) - (max_H_index + 1));

        if(right_second_L != max_L){
            rightBox(right_second_L, right_second_H); //오른쪽으로
        }
    }
    
    cout << origin_extent <<"\n";
}

// 투포인터 방법