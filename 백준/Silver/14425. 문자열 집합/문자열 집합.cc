#include <iostream>

using namespace std;

class Node { // 트라이 자료 구조 저장용 클래스
public: 
    Node* next[26]; //알파벳 26진트리
    bool isEnd; //리프노드 표시
    Node() : isEnd(false) {
        fill(next, next + 26, nullptr);
    }

    ~Node() {
        for (auto& child : next)
            delete child;
    }

    void insert(const char* key) { //문자열 삽입 함수
        if (*key == 0) {
            isEnd = true;
        } else {
            int next_index = *key - 'a';
            if (next[next_index] == nullptr) {
                next[next_index] = new Node();
            }
            next[next_index] -> insert(key + 1);
        }
    }

    Node* find(const char* key) { //문자열 찾기 함수
        if (*key == 0) {
            return this;
        }
        int next_index = *key - 'a';

        if (next[next_index] == nullptr) {
            return nullptr;
        }
        return next[next_index] -> find(key + 1);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    Node* root = new Node();

    for(int i = 0; i < n; i++) {
        char text[501];
        cin >> text;
        root -> insert(text);
    }

    int count = 0;
    for(int i = 0; i < m; i++) {
        char text[501];
        cin >> text;
        Node* result = root -> find(text);

        if (result && result -> isEnd) {
            count++;
        }
    }

    cout << count;
}