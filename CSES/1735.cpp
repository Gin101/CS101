#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

#define int long long
const int maxN = 2e5 + 1;
long long x[maxN] = {0};
long long _data[maxN * 4] = {0};
long long _data2[maxN * 4] = {0};
long long tree[maxN * 4] = {0};
long long tree2[maxN * 4] = {0};

void push(int num, int l, int r) {
    if (l != r) {
        _data[num * 2] += _data[num];
        _data[num * 2 + 1] += _data[num];
    }
    tree[num] += (r - l + 1) * _data[num];
    _data[num] = 0;
}

void update(int l, int r, int num, int a, int b, int idx) {
    if (l <= a && b <= r) {
        tree[idx] += (b - a + 1) * num;
        _data[idx] += num;
        return;
    }

    if (_data[idx] && a != b) {
        tree[idx * 2] += _data[idx] * ((b - a) / 2 + 1);
        tree[idx * 2 + 1] += _data[idx] * (b - (b - a) / 2 + 1);
        _data[idx * 2] += _data[idx];
        _data[idx * 2 + 1] += _data[idx];
        _data[idx] = 0;
    }

    if (l <= (b - a) / 2 + 1)  {
        update(l, r, num, a, (b - a) / 2 + 1, idx * 2);
    }
    if (r > (b - a) / 2 + 1) {
        update(l, r, num, (b - a) / 2 + 2, r, idx * 2 + 1);
    }
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
}

void update2(int l, int r, int num, int a, int b, int idx) {
    if (l <= a && b <= r) {
        tree[idx] = (b - a + 1) * num;
        _data[idx] = num;
        return;
    }

    if (tree[idx]) {
        tree[idx * 2] = _data[idx] * (((b - a)) / 2 + 1);
        tree[idx * 2 + 1] = _data[idx] * (b - a + ((b - a)) / 2);
        _data[idx * 2] = _data[idx];
        _data[idx * 2 + 1] = _data[idx];
    }
}

void update(int l, int r, int c, int s, int t, int p) {
  if (l <= s && t <= r) {
    d[p] = (t - s + 1) * c, b[p] = c;
    return;
  }
  int m = s + ((t - s) >> 1);
  if (v[p]) {
    d[p * 2] = b[p] * (m - s + 1), d[p * 2 + 1] = b[p] * (t - m);
    b[p * 2] = b[p * 2 + 1] = b[p];
    v[p * 2] = v[p * 2 + 1] = 1;
    v[p] = 0;
  }
  if (l <= m) update(l, r, c, s, m, p * 2);
  if (r > m) update(l, r, c, m + 1, t, p * 2 + 1);
  d[p] = d[p * 2] + d[p * 2 + 1];
}

int query(int l, int r, int a, int b, int idx) {
    if (l <= a && b <= r) {
        return tree[idx];
    }

    int result = 0;
    if (l <= a + (b - a) / 2) {
        result += query(l, r, a, b, idx * 2);
    }
    if (r > a + (b - a) / 2) {
        result += query(l, r, a + (b - a) / 2 + 1, b, idx * 2 + 1);
    }
}

signed main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        x[i] += x[i - 1];
        update(1, 1, n, x[i], i, i);
    }

    for (int i = 0; i < q; i++) {
        int o = 0;
        int a = 0;
        int b = 0;
        cin >> o >> a >> b;
        if (o == 1) {
            int num = 0;
            cin >> num;

            update(1, 1, n, num, a, b);
        } else {
            cout << query(1, n, a, b, 1)
        }
    }

    return 0;
}