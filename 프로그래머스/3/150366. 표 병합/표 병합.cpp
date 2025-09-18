#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

string map[51][51];

vector<string> split(string& str, char delimiter) {
    vector<string> res;
    stringstream iss(str);
    string word;
    while (getline(iss, word, delimiter)) {
        res.push_back(word);
    }
    return res;
}

int parent[2700];
unordered_map<string, vector<int>> stringMap; // (유지하되 사용은 안함)

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionFunc(int a, int b) {
    a = find(a);
    b = find(b);
    if (a != b) parent[b] = a;
}

// 1-based 인덱싱으로 고정
static inline int idx(int r, int c) { return (r - 1) * 50 + c; }

vector<string> solution(vector<string> commands) {
    vector<string> answer;

    // 1..2500 으로 초기화 (중요)
    for (int i = 1; i <= 2500; i++) parent[i] = i;

    for (string c : commands) {
        vector<string> sp = split(c, ' ');
        string command = sp[0];

        if (command == "UPDATE") {
            // 형태 1) UPDATE r c value
            // 형태 2) UPDATE value1 value2
            if (sp.size() == 4) {
                int r = stoi(sp[1]);
                int c = stoi(sp[2]);
                string v = sp[3];
                int root = find(idx(r, c));

                // 같은 루트를 가진 모든 셀을 스캔하며 값 갱신 (2500칸 전수 스캔)
                for (int rr = 1; rr <= 50; ++rr) {
                    for (int cc = 1; cc <= 50; ++cc) {
                        if (find(idx(rr, cc)) == root) map[rr][cc] = v;
                    }
                }
            } else {
                // UPDATE value1 value2
                string os = sp[1];
                string ns = sp[2];
                // stringMap 대신 전수 스캔 (단순/안전)
                for (int rr = 1; rr <= 50; ++rr) {
                    for (int cc = 1; cc <= 50; ++cc) {
                        if (map[rr][cc] == os) map[rr][cc] = ns;
                    }
                }
            }
        }
        else if (command == "MERGE") {
            int r1 = stoi(sp[1]);
            int c1 = stoi(sp[2]);
            int r2 = stoi(sp[3]);
            int c2 = stoi(sp[4]);
            int a = idx(r1, c1);
            int b = idx(r2, c2);
            int ra = find(a), rb = find(b);
            if (ra == rb) continue; // 이미 같은 그룹이면 아무 것도 안 함

            // 병합 전 값 결정: (r1,c1) 값 우선, 비어있으면 (r2,c2)
            string keep = map[r1][c1].empty() ? map[r2][c2] : map[r1][c1];

            unionFunc(ra, rb);
            int rnew = find(a); // 새 루트

            // 새 루트 그룹의 모든 셀을 keep 값으로 통일 (전수 스캔)
            for (int rr = 1; rr <= 50; ++rr) {
                for (int cc = 1; cc <= 50; ++cc) {
                    if (find(idx(rr, cc)) == rnew) map[rr][cc] = keep;
                }
            }
        }
        else if (command == "UNMERGE") {
            int r = stoi(sp[1]);
            int c = stoi(sp[2]);
            string s = map[r][c];
            int root = find(idx(r, c));

            // 같은 루트에 속한 모든 셀을 찾아서 분리 + 값 비우기
            for (int rr = 1; rr <= 50; ++rr) {
                for (int cc = 1; cc <= 50; ++cc) {
                    int id = idx(rr, cc);
                    if (find(id) == root) {
                        parent[id] = id;      // 분리
                        map[rr][cc].clear();  // 값 제거
                    }
                }
            }
            // 해당 셀만 값 복원
            map[r][c] = s;
        }
        else if (command == "PRINT") {
            int r = stoi(sp[1]);
            int c = stoi(sp[2]);
            if (map[r][c].empty()) answer.push_back("EMPTY");
            else answer.push_back(map[r][c]);
        }
    }
    return answer;
}
