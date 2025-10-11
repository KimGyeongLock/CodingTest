#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

struct Node {  
    int x, y, idx;
    int left = -1, right = -1;
};

void insertNode(vector<Node>& nodes, int root, int child) {
    int cur = root;
    while (true) {
        if (nodes[child].x < nodes[cur].x) {
            if (nodes[cur].left == -1) {
                nodes[cur].left = child;
                break;
            } else cur = nodes[cur].left;
        } else {
            if (nodes[cur].right == -1) {
                nodes[cur].right = child;
                break;
            } else cur = nodes[cur].right;
        }
    }
}

void preorder(const vector<Node>& nodes, int u, vector<int>& out) {
    if (u == -1) return;
    out.push_back(nodes[u].idx);
    preorder(nodes, nodes[u].left, out);
    preorder(nodes, nodes[u].right, out);
}

void postorder(const vector<Node>& nodes, int u, vector<int>& out) {
    if (u == -1) return;
    postorder(nodes, nodes[u].left, out);
    postorder(nodes, nodes[u].right, out);
    out.push_back(nodes[u].idx);
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    int n = nodeinfo.size();
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++) {
        nodes[i] = {nodeinfo[i][0], nodeinfo[i][1], i+1, -1, -1};
    }
    
    vector<int> order(n);
    iota(order.begin(), order.end(), 0); // 0, 1, 2, 3, ... n-1
    sort(order.begin(), order.end(), [&](int a, int b) {
        if (nodes[a].y != nodes[b].y) return nodes[a].y > nodes[b].y;
        return nodes[a].x < nodes[b].x;
    });
    
    int root = order[0];
    for (int i = 1; i < n; i++) {
        insertNode(nodes, root, order[i]);
    }
    
    vector<int> pre, post;
    pre.reserve(n); post.reserve(n);
    preorder(nodes, root, pre);
    postorder(nodes, root, post);
    
    return {pre, post};
}