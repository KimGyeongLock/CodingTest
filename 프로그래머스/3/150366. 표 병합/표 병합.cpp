#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> parent(2501);
vector<string> vec(2501, "");

int id (int r, int c){ return (r-1)*50 + c; }

vector<string> split(string s) {
    vector<string> res;
    stringstream iss(s);
    string word;
    while(getline(iss, word, ' ')) {
        res.push_back(word);
    }
    return res;
}

int find(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find(parent[x]);
}

void unionfunc(int a, int b) {
    a = find(a);
    b = find(b);
    
    if (a != b) {
        parent[b] = a; 
    }
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for (int i = 1; i <= 2500; i++) parent[i] = i;
    
    for (auto& c : commands) {
        vector<string> sp = split(c);
        
        if (sp[0] == "UPDATE") {
            if (sp.size() == 4) {
                int r = stoi(sp[1]);
                int c = stoi(sp[2]);  
                string value = sp[3];
                
                int root = find(id(r, c));
                vec[root] = value;
            } else if (sp.size() == 3) {
                string value1 = sp[1];
                string value2 = sp[2];
                
                for (int i = 0; i <= 2500; i++) {
                    if (vec[i] == value1) {
                        vec[find(i)] = value2;
                    }
                }
            }
            
        } else if (sp[0] == "MERGE") {
            int r1 = stoi(sp[1]), c1 = stoi(sp[2]), r2 = stoi(sp[3]), c2 = stoi(sp[4]);

            int a = find(id(r1,c1));
            int b = find(id(r2,c2));

            string keep = !vec[a].empty() ? vec[a] : vec[b];

            unionfunc(a, b);
            vec[b] = "";
            vec[a] = keep;

        } else if (sp[0] == "UNMERGE") {
            int r = stoi(sp[1]), c = stoi(sp[2]);
            int target = id(r,c);
            int root = find(target);
            string keep = vec[root];

            vector<int> members;
            members.reserve(2500);
            for (int i = 1; i <= 2500; i++) {
                if (find(i) == root) members.push_back(i);
            }

            // 2) 이제 안전하게 분리
            for (int x : members) {
                parent[x] = x;
                vec[x] = "";
            }

            // 3) target만 값 복구
            vec[target] = keep;
    } else if (sp[0] == "PRINT") {
            int r = stoi(sp[1]), c = stoi(sp[2]);
            answer.push_back(vec[find(id(r, c))] == "" ? "EMPTY" : vec[find(id(r, c))]); 
        }
    }
    return answer;
}