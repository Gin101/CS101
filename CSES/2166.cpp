#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define int long long

int n = 0;
const int maxN = 5e5 + 1;

struct Node {
    long long cnt;
    long long sum;
    Node() {
        cnt = 0;
        sum = LONG_MIN;
    }
} tree[maxN * 4];

Node merge(Node l, Node r) {
    Node result;
    result.cnt = l.cnt + r.cnt;
    result.sum = max(r.sum + l.cnt, l.sum);

    return result;
}

void update(int num, int val, int idx = 1, int l = 1, int r = n) {
    if (l == r) {
        tree[idx].cnt = val;
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

Node query(int a, int b, int idx = 1, int l = 1, int r = n) {
    if (r < a || l > b) {
        return tree[0];
    }
    if (a <= l && r <= b) {
        return tree[idx];
    }

    return merge(query(a, b, idx * 2, l, (l + r) / 2), query(a, b, idx * 2 + 1, (l + r) / 2 + 1, r));
}   

signed main()
{
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x;
        update(i, x);
    }

    for (int i = 0; i < q; i++) {
        int o = 0;
        cin >> o;

        if (o == 1) {
            int k = 0;
            int u = 0;
            cin >> k >> u;

            update(k, u);
        } else {
            int a = 0;
            int b = 0;
            cin >> a >> b;

            cout << max(query(a, b).sum, 0ll) << endl;
        }
    }

    return 0;
}