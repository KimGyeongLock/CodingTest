#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    
    vector<char> inHand(n + 1, false), inField(n + 1, false);
    int idx = 0; // 현재 위치 n / 3 - 1
    for (; idx < n / 3; idx++) 
        inHand[cards[idx]] = true;
    
    vector<pair<int, int>> HH;
    HH.reserve(n);
    for (int x = 1; x <= n; x++) {
        if (inHand[x]) {
            int y = n + 1 - x;
            if (inHand[y]) HH.push_back({x, y});
        }
    }
    vector<int> HF;
    HF.reserve(n);
    vector<pair<int,int>> FF;
    FF.reserve(n);
    
    auto push_field = [&](int c) {
        if (inField[c]) return;
        int y = n + 1 - c;
        if (inField[y]) FF.push_back({min(c, y), max(c, y)});
        if (inHand[y]) HF.push_back(y);
        inField[c] = true;
    };
    
    auto reveal = [&]() {
        if (idx < n) push_field(cards[idx++]);
        if (idx < n) push_field(cards[idx++]);
    };
    
    auto try_HH = [&]()->bool{
        while (!HH.empty()) {
            auto [a, b] = HH.back();
            if (inHand[a] && inHand[b]) {
                inHand[a] = inHand[b] = false;
                return true;
            }
            HH.pop_back();
        }  
        return false;
    };
    
    auto try_HF = [&]()->bool{
        while (!HF.empty()) {
            int h = HF.back(); HF.pop_back();
            int c = n + 1 - h;
            if (inHand[h] && inField[c]) {
                inHand[h] = false;
                inField[c] = false;
                return true;
            }
        }  
        return false;
    };
    
    auto try_FF = [&]()->bool{
        while (!FF.empty()) {
            auto [a, b] = FF.back();
            FF.pop_back();
            if (inField[a] && inField[b]) {
                inField[a] = inField[b] = false;
                return true;
            }
        }  
        return false;
    };
    
    int turn = 1;
    while (true) {
        if (idx >= n) break;
        
        reveal();
        
        bool played = false;
        if (try_HH()) {
            played = true;
        } else if (coin > 0 && try_HF()) {
            coin -= 1; played = true;
        } else if (coin >= 2 && try_FF()) {
            coin -= 2; played = true;
        }
        
        if (!played) break;
        turn++;
    }
    return turn;
}