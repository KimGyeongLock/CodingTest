#include <iostream>
#include <queue>

using namespace std;

int sender[] = {0, 0, 1, 1, 2, 2};
int receiver[] = {1, 2, 0, 2, 0, 1};

int now[3];
bool answer[201];
bool visited[201][201]; //A와 B 용량 체크

void BFS() {
    queue<pair<int, int> > myqueue;
    myqueue.push(make_pair(0, 0));
    visited[0][0] = true;
    answer[now[2]] = true;

    while (!myqueue.empty())
    {
        pair<int, int> p = myqueue.front();
        myqueue.pop();
        int A = p.first;
        int B = p.second;
        int C = now[2] - A - B;

        for(int i = 0; i < 6; i++) {
            int next[] = { A, B, C };
            next[receiver[i]] += next[sender[i]];
            next[sender[i]] = 0;
            if (next[receiver[i]] > now[receiver[i]]) {
                next[sender[i]] += (next[receiver[i]] - now[receiver[i]]);
                next[receiver[i]] = now[receiver[i]];
            }

            if(!visited[next[0]][next[1]]) {
                myqueue.push(make_pair(next[0], next[1]));
                visited[next[0]][next[1]] = true;
                if (next[0] == 0) {
                    answer[next[2]] = true;
                }
            }
        }
    }
    
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> now[0] >> now[1] >> now[2];

    BFS();
    for(int i = 0; i < 201; i++) {
        if(answer[i]) {
            cout << i << " ";
        }
    }
}