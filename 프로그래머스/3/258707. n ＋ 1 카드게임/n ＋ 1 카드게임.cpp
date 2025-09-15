#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    
    vector<bool> inHand(n + 1, false), inField(n + 1, false);
    int idx = 0;
    for (; idx < n / 3; idx++) {
        inHand[cards[idx]] = true;
    }
    
    vector<pair<int, int>> HH;
    HH.reserve(n);
    for (int i = 1; i <= n; i++) {
        if (inHand[i]) {
            int y = n + 1 - i;
            if (inHand[y] && i < y) {
                HH.push_back({i, y});
            }
        }
    }
    
    vector<pair<int, int>> FF;
    FF.reserve(n);
    vector<int> HF;
    HF.reserve(n);
    
    auto push_field = [&](int c) {
        int y = n + 1 - c;
        if (inHand[y]) HF.push_back(y);
        if (inField[y]) FF.push_back({c, y});
        inField[c] = true;
    };
    
    auto reveal = [&]() {
        if (idx < n) push_field(cards[idx++]);
        if (idx < n) push_field(cards[idx++]);
    };
    
    auto try_HH = [&]()->bool{
        while (!HH.empty()) {
            auto [a, b] = HH.back();
            HH.pop_back();
            if (inHand[a] && inHand[b]) {
                inHand[a] = inHand[b] = false;
                return true;
            }
        }
        return false;
    };
    
    auto try_HF = [&]()->bool{
        while (!HF.empty()) {
            int a = HF.back();
            int b = n + 1 - a;
            HF.pop_back();
            if (inHand[a] && inField[b]) {
                inHand[a] = false;
                inField[b] = false;
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
        bool played = false;
        
        reveal();
        
        if (try_HH()) {
            played = true;
        } else if (coin > 0 && try_HF()) {
            coin -= 1;
            played = true;
        } else if (coin >= 2 && try_FF()) {
            coin -= 2;
            played = true;
        }
        
        if (!played) break;
        turn++;
    }
    return turn;
}