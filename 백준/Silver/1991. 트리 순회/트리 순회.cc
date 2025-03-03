#include <iostream>
#include <vector>

using namespace std;

vector<vector<char> > binary_tree;

void preorder(char c) {
    if (c == '.') {
        return;
    }
    cout << c;
    preorder(binary_tree[c][0]);
    preorder(binary_tree[c][1]);
}

void inorder(char c) {
    if (c == '.') {
        return;
    }
    inorder(binary_tree[c][0]);
    cout << c;
    inorder(binary_tree[c][1]);
}

void postorder(char c) {
    if (c == '.') {
        return;
    }
    postorder(binary_tree[c][0]);
    postorder(binary_tree[c][1]);
    cout << c;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    binary_tree.resize(N);
    for(int i = 0; i < N; i++) {
        char a, b, c;
        cin >> a >> b >> c;
        
        binary_tree[a].push_back(b);
        binary_tree[a].push_back(c);
    }

    preorder('A');
    cout << "\n";
    inorder('A');
    cout << "\n";
    postorder('A');
}