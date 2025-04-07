#include <iostream>
#include <vector>

using namespace std;

vector<long> tree;

long getSum(int s, int e) {
    long partSum = 0;

    while(s <= e) {
        if (s % 2 == 1) {
            partSum += tree[s];
            s++;
        }
        if (e % 2 == 0) {
            partSum += tree[e]; 
            e--;
        }
        s = s / 2;
        e = e / 2;
    }
    return partSum;
}

void changeVal(int index, long val) {
    long diff = val - tree[index];

    while(index > 0) {
        tree[index] = tree[index] + diff;
        index = index / 2;
    }
}

void setTree(int i) {
    while(i != 1) {
        tree[i / 2] += tree[i];
        i--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, Q;
    cin >> N >> Q;

    // 2^(treeHight) >= Length
    int treeHight = 0;
    int Length = N;
    while(Length != 0) {
        Length /= 2;
        treeHight++;
    }
    int treeSize = int(pow(2, treeHight + 1)); // 트리 배열의 크기 = 2^(treeHight) * 2
    int leftNodeStartIndex = treeSize / 2 - 1; // 1 ~ 16 가운데 7
    tree.resize(treeSize + 1);

    for(int i = leftNodeStartIndex + 1; i <= leftNodeStartIndex + N; i++) {
        cin >> tree[i];
    }

    setTree(treeSize - 1);

    for(int i = 0; i < Q; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        if (n1 == 1) {
            n2 = n2 + leftNodeStartIndex;
            n3 = n3 + leftNodeStartIndex;
            cout << getSum(n2, n3) << "\n"; 
        } else if (n1 == 2) {
            changeVal(leftNodeStartIndex + n2, tree[leftNodeStartIndex + n2] + n3);
        } else if (n1 == 3) {
            changeVal(leftNodeStartIndex + n2, tree[leftNodeStartIndex + n2] - n3);
        }
    }

}
