#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define int long long
const int maxN = 2e5 + 1;
long long _data[maxN * 4] = {0};
long long tree[maxN * 4] = {0};

void push(int num, int l, int r) {
    if (l != r) {
        _data[num * 2] += _data[num];
        _data[num * 2 + 1] += _data[num];
    }
    tree[num] += (r - l + 1) * _data[num];
    _data[num] = 0;
}

void update(int num, int l, int r, long long val, int a, int b) {
    push(num, l, r);
    if (r < a || l > b) {
        return;
    }

    if (a <= l && b >= r) {
        _data[num] += val;
        push(num, l, r);
        return;
    }

    update(num * 2, l, (l + r) / 2, val, a, b);
    update(num * 2 + 1, (l + r) / 2 + 1, r, val, a, b);
}

int query(int num, int l, int r, long long val) {
    push(num, l, r);
    if (l == r) {
        return tree[num];
    }

    if (val <= (l + r) / 2) {
        return query(num * 2, l, (l + r) / 2, val);
    }
    return query(num * 2 + 1, (l + r) / 2 + 1, r, val);
}

signed main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        long long x = 0;
        cin >> x;
        update(1, 1, n, x, i, i);
    }

    for (int i = 0; i < q; i++) {
        int o = 0;
        cin >> o;

        if (o == 1) {
            int a = 0;
            int b = 0;
            long long u = 0;
            cin >> a >> b >> u;

            update(1, 1, n, u, a, b);
        } else {
            long long k = 0;
            cin >> k;

            cout << query(1, 1, n, k) << endl;
        }
    }

    return 0;
}