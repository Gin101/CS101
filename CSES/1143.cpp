#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
const int maxN = 2e5 + 1;
int h[maxN] = {0};
int tree[maxN * 4] = {0};

void build(int num, int l, int r) {
    if (l == r) {
        tree[num] = h[l];
        return;
    }

    build(num * 2, l, (l + r) / 2);
    build(num * 2 + 1, (l + r) / 2 + 1, r);
    tree[num] = max(tree[num * 2], tree[num * 2 + 1]);
}

void update(int val, int num, int l, int r) {
    if (l == r) {
        tree[num] -= val;
        cout << l << ' ';
    } else {
        if (tree[num * 2] >= val) {
            update(val, num * 2, l, (l + r) / 2);
        } else {
            update(val, num * 2 + 1, (l + r) / 2 + 1, r);
        }
        tree[num] = max(tree[num * 2], tree[num * 2 + 1]);
    }
}

int main()
{
    int q = 0;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

    build(1, 1, n);
    for (int i = 0; i < q; i++) {
        int r = 0;
        cin >> r;

        if (tree[1] < r) {
            cout << 0 << ' ';
        } else {
            update(r, 1, 1, n);
        }
    }

    cout << endl;

    return 0;
}