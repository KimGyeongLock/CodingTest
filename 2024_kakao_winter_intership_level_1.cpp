#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

/**
 선물을 주고받은 기록이 있다면
 더 많은 선물을 준 사람 -> 다음달에 선물을 받는다.
 
 선물을 주고받은 기록이 없다면 (또는 같다면)
 선물 지수가 더 작은 사람이 -> 더 큰 사람에게
 선물 지수 = 친구들에게 준 선물의 수 - 받은 선물의 수
 
 선물 지수도 같다면 선물을 주고 받지 않음
 
 선물을 가장 많이 받을 친구의 받을 선물의 수
 
 friedns : 친구들의 이름
 gifts : 이번달까지 주고 받은 선물 기록
 
 다음달에 가장 많은 선물을 받는 친구가 받을 선물의 수를 반환
 
 muzi -> 
*/

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
    
    while(getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
    return answer;
}


int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    // 1. 각 친구의 선물 지수를 저장할 map
    map<string, int> giftIndex;
    for(string friend_name : friends) {
        giftIndex[friend_name] = 0;
    }
    
    // 2. 선물 기록을 파싱하여 각 친구의 준 선물, 받은 선물 개수 카운트
    map<pair<string, string>, int> giftMap;
    map<string, int> givenCount;
    map<string, int> receivedCount;
    for(string gift : gifts) {
        vector<string> parsedGift = split(gift, ' ');
        string giver = parsedGift[0];
        string receiver = parsedGift[1];
        
        giftMap[{giver, receiver}]++;
        givenCount[giver]++;
        receivedCount[receiver]++;
    }
    
    // 3. 각 친구의 선물 지수를 계산
    for(string friend_name : friends) {
        giftIndex[friend_name] = givenCount[friend_name] - receivedCount[friend_name];
    }
    
    // 4. 다음달에 받을 선물 수를 계산할 map
    map<string, int> nextMonthReceived;
    for(string friend_name : friends) {
        nextMonthReceived[friend_name] = 0;
    }
    
    // 5. 선물 기록을 바탕으로 다음 달에 받을 선물 수 예측
    for(int i = 0; i < friends.size(); i++) {
        for(int j = i + 1; j < friends.size(); j++) {
            string giver = friends[i];
            string receiver = friends[j];

            int given_to_receiver = giftMap[{giver, receiver}]; //receiver가 giver에게 받은 갯수
            int given_to_giver = giftMap[{receiver, giver}]; //giver가 receiver에게 받은 갯수

            cout << giver << " -> " << receiver << " = " << given_to_receiver << "\n";
               cout << receiver << " -> " << giver << " = " << given_to_giver << "\n";

            if (given_to_receiver > given_to_giver) {
                nextMonthReceived[giver]++;
            } else if (given_to_receiver < given_to_giver) {
                nextMonthReceived[receiver]++;
            } else {
                if (giftIndex[receiver] > giftIndex[giver]) {
                    nextMonthReceived[receiver]++;
                } else if (giftIndex[receiver] < giftIndex[giver]) {
                    nextMonthReceived[giver]++;
                }
            }
        }
    }
    
    // 6. 가장 많은 선물을 받을 친구의 수 계산
    for (auto& record : nextMonthReceived) {
        answer = max(answer, record.second);
    }
    
    return answer;
}