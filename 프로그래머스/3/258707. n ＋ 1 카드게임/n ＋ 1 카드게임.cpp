#include <bits/stdc++.h>
using namespace std;

static inline int partner(int n, int x) { return n + 1 - x; }

int solution(int coin, vector<int> cards) {
    const int n = (int)cards.size();

    vector<char> inHand(n + 1, false), inField(n + 1, false);

    // 초기 손패: 앞의 n/3장
    int idx = 0;
    for (; idx < n / 3; ++idx) inHand[cards[idx]] = true;

    // 0코인 후보(손패-손패): 초기 한 번만 구성
    vector<pair<int,int>> HH; HH.reserve(n);
    for (int x = 1; x <= n; ++x) if (inHand[x]) {
        int y = partner(n, x);
        if (1 <= y && y <= n && inHand[y] && x < y) HH.push_back({x, y});
    }

    // 1코인 후보(손패-필드): 손패 측 값만 저장 (h)
    vector<int> HF; HF.reserve(n);

    // 2코인 후보(필드-필드)
    vector<pair<int,int>> FF; FF.reserve(n);

    auto push_field = [&](int c) {
        if (inField[c]) return;
        int y = partner(n, c);
        if (1 <= y && y <= n && inField[y]) FF.push_back({min(c, y), max(c, y)});
        if (1 <= y && y <= n && inHand[y])  HF.push_back(y);
        inField[c] = true;
    };

    auto reveal = [&](){
        if (idx < n) push_field(cards[idx++]);
        if (idx < n) push_field(cards[idx++]);  // 남아 있으면 두 장까지
    };

    auto try_HH = [&]()->bool{
        while (!HH.empty()) {
            auto [a, b] = HH.back();
            if (inHand[a] && inHand[b]) {
                inHand[a] = inHand[b] = false;
                return true;
            }
            HH.pop_back(); // 무효 후보 버림
        }
        return false;
    };

    auto try_HF = [&]()->bool{
        while (!HF.empty()) {
            int h = HF.back(); HF.pop_back();
            int c = partner(n, h);
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
            auto [a, b] = FF.back(); FF.pop_back();
            if (inField[a] && inField[b]) {
                inField[a] = inField[b] = false;
                return true;
            }
        }
        return false;
    };

    int turn = 0;
    while (true) {
        // ✅ 덱이 완전히 비면 곧바로 종료 (라운드 시작 불가)
        if (idx >= n) break;

        // 매 라운드 시작: 최대 2장 공개
        reveal();

        bool played = false;
        if (try_HH()) {
            played = true;                // 0코인
        } else if (coin > 0 && try_HF()) {
            coin -= 1; played = true;     // 1코인
        } else if (coin >= 2 && try_FF()) {
            coin -= 2; played = true;     // 2코인
        }

        if (!played) break;  // 어떤 방법도 불가 → 종료
        ++turn;              // 생존한 라운드 수
    }

    return turn + 1;
}
