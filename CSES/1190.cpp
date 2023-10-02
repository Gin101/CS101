#include <iostream>

using namespace std;

int n = 0;
const int maxN = 5e5 + 1;

struct Node {
    long long num;
    long long sum;
    long long pre;
    long long idx;
    Node() {
        num = 0;
        sum = 0;
        pre = 0;
        idx = 0;
    }
} tree[maxN * 4];

Node merge(Node l, Node r) {
    Node result;
    result.sum = l.sum + r.sum;
    result.pre = max(r.pre + l.sum, l.pre);
    result.idx = max(l.idx + r.sum, r.idx);
    result.num = max(l.num, max(r.num, l.idx + r.pre));
    return result;
}

void update(int num, int val, int idx = 1, int l = 1, int r = n) {
    if (l == r) {
        tree[idx].num = max(0, val);
        tree[idx].pre = max(0, val);
        tree[idx].idx = max(0, val);
        tree[idx].sum = val;
        return;
    }

    if (num <= (l + r) / 2) {
        update(num, val, idx * 2, l, (l + r) / 2);
    } else {
        update(num, val, idx * 2 + 1, (l + r) / 2 + 1, r);
    }
    tree[idx] = merge(tree[idx * 2], tree[idx * 2 + 1]);
}

int main()
{
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x;
        update(i, x);
    }

    for (int i = 0; i < q; i++) {
        int k = 0;
        int x = 0;
        cin >> k >> x;

        update(k, x);

        cout << tree[1].num << endl;
    }

    return 0;
}