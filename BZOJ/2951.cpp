#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 15001;
int tmp[maxN * 4] = {0};
struct Node {
    int x;
    int y;
    int num;
} e[maxN * 4];
struct Node2 {
    int s;
    int m;
} tree[maxN * 16];
bool cmp(Node x, Node y) {
    return x.x < y.x;
}

void update(int k, int l, int r, int x, int p) {
    if (l == r) {
        return tree[k].s += p, tree[k].m += p, void();
    }
    if (x <= (l + r) / 2) {
        update(k * 2, l, (l + r) / 2, x, p);
    } else {
        update(k * 2 | 1, (l + r) / 2 + 1, r, x, p);
    }
    tree[k] = (Node2){tree[k * 2].s + tree[k * 2 | 1].s, max(tree[k * 2].m, tree[k * 2].s + tree[k * 2 | 1].m)};
}

int main()
{
    int s = 0;
    int w = 0;
    int n = 0;
    cin >> s >> w >> n;
    s++;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[++idx] = (Node){x, y, 1};
        e[++idx] = (Node){x, y + w, -1};
        e[++idx] = (Node){x + s, y, -1};
        e[++idx] = (Node){x + s, y + w, 1};
    }

    sort(e + 1, e + idx + 1, cmp);
    e[idx + 1].x = -1;
    for (int i = 1; i <= idx; i++) {
        tmp[i] = e[i].y;
    }
    sort(tmp + 1, tmp + idx + 1);
    n = unique(tmp + 1, tmp + idx + 1) - tmp - 1;
    for (int i = 1; i <= idx; i++) {
        e[i].y = lower_bound(tmp + 1, tmp + n + 1, e[i].y) - tmp;
    }

    int result = 0;
    for (int i = 1; i <= idx; i++) {
        while(e[i].x == e[i + 1].x) {
            update(1, 1, n, e[i].y, e[i].num);
            i++;
        }
        update(1, 1, n, e[i].y, e[i].num);
        result = max(tree[1].m, result);
    }

    cout << result << endl;

    return 0;
}