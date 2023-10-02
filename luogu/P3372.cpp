#include <iostream>

using namespace std;

#define int long long
const int maxN = 1e5 + 1;
int num[maxN] = {0};
int d[maxN * 4] = {0};
int b[maxN * 4] = {0};

void build(int s, int t, int p) {
    if (s == t) {
        d[p] = num[s];
        return;
    }

    int mid = s + (t - s) / 2;
    build(s, mid, p * 2);
    build(mid + 1, t, p * 2 + 1);
    d[p] = d[p * 2] + d[p * 2 + 1];
}
void update(int s, int t, int l, int r, int p, int c) {
    if (l <= s && t <= r) {
        d[p] += (t - s + 1) * c;
        b[p] += c;
        return;
    }

    int mid = s + (t - s) / 2;
    if (b[p] && s != t) {
        d[p * 2] += (mid - s + 1) * b[p];
        d[p * 2 + 1] += (t - mid) * b[p];
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }

    if (l <= mid) {
        update(s, mid, l, r, p * 2, c);
    }
    if (r > mid) {
        update(mid + 1, t, l, r, p * 2 + 1, c);
    }
    d[p] = d[p * 2] + d[p * 2 + 1];
}

int getsum(int s, int t, int l, int r, int p) {
    if (l <= s && t <= r) {
        return d[p];
    }

    int mid = s + (t - s) / 2;
    if (b[p]) {
        d[p * 2] += (mid - s + 1) * b[p];
        d[p * 2 + 1] += (t - mid) * b[p];
        b[p * 2] += b[p];
        b[p * 2 + 1] += b[p];
        b[p] = 0;
    }

    int sum = 0; 
    if (l <= mid) {
        sum += getsum(s, mid, l, r, p * 2);
    } 
    if (r > mid) {
        sum += getsum(mid + 1, t, l, r, p * 2 + 1);
    }
    return sum;
}

signed main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    build(1, n, 1);
    for (int i = 0; i < m; i++) {
        int op = 0;
        int x = 0;
        int y = 0;
        cin >> op >> x >> y;

        if (op == 1) {
            int k = 0;
            cin >> k;

            update(1, n, x, y, 1, k);
        } else {
            cout << getsum(1, n, x, y, 1) << endl;
        }
    }

    return 0;
}