#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
const int maxN = 1e6 + 1;
const int maxQ = 3e4 + 1;

struct Node {
    int l = 0;
    int r = 0;
    int x = 0;
} num[maxQ], tmp[maxQ];

bool cmp(Node x, Node y) {
    if (x.x == y.x) {
        return x.l < y.l;
    }
    return x.x > y.x;
}
int f[maxN] = {0};

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

bool check(int x) {
    for (int i = 1; i <= n + 1; i++) {
        f[i] = i;
    }

    for (int i = 1; i <= x; i++) {
        tmp[i] = num[i];
    }

    sort(tmp + 1, tmp + x + 1, cmp);

    int tmp2 = tmp[1].x;
    int lx = tmp[1].l;
    int ln = tmp[1].l;
    int rx = tmp[1].r;
    int rn = tmp[1].r;
    for (int i = 2; i <= x; i++) {
        if (tmp2 == tmp[i].x) {
            lx = max(lx, tmp[i].l);
            ln = min(ln, tmp[i].l);
            rx = max(rx, tmp[i].r);
            rn = min(rn, tmp[i].r);
            if (lx > rn) {
                return 0;
            }
        } else {
            if (find(lx) > rn) {
                return 0;
            }

            int idx = find(ln);
            while (idx <= rx) {
                f[idx] = f[idx + 1];
                idx = find(idx + 1);
            }

            tmp2 = tmp[i].x;
            lx = tmp[i].l;
            ln = tmp[i].l;
            rx = tmp[i].r;
            rn = tmp[i].r;
        }
    }

    return find(lx) <= rn;
}

int main()
{
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= q; i++) {
        cin >> num[i].l >> num[i].r >> num[i].x;
    }

    int l = 0;
    int r = q + 1;
    while (l < r - 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    if (r == q + 1) {
        cout << 0 << endl;
    } else {
        cout << r << endl;
    }

	return 0;
}