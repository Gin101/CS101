#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n = 0;
int idx = 0;
int cnt = 0;
int tmp = 0;
const int maxN = 1e5 + 1;
int f[maxN] = {0};
int num[maxN] = {0};
int num2[maxN] = {0};

struct Node {
    int l = 0;
    int r = 0;
    vector<int> v;
} tree[maxN * 40];

int find(int x) {
    if (f[x] == x) {
        return x;
    }
    return f[x] = find(f[x]);
}

void Union(int& idx2, int l,int r, int k) {
    if (!idx2) {
        return;
    }

    for (int i = 0; i < tree[idx2].v.size(); i++) {
        num[idx] = min(num[idx], num[find(tree[idx2].v[i])]);
        num2[idx] = max(num2[idx], num[find(tree[idx2].v[i])]);
        f[find(i)] = idx;
    }

    tree[idx2].v.clear();
    if (l == r) {
        return;
    }
    if (k <= (l + r) / 2) {
        Union(tree[idx].l, l, (l + r) / 2, k);
    } else {
        Union(tree[idx].r, (l + r) / 2 + 1, r, k);
    }
}

void cover(int& idx, int a, int b, int l, int r) {
    if (!idx) {
        idx = ++cnt;
    }

    if (l <= a && b <= r) {
        tree[idx].v.push_back(idx);
        return;
    }
    if (r <= (a + b) / 2) {
        cover(tree[idx].l, a, (a + b) / 2, l, r);
    } else if ((a + b) / 2 < l) {
        cover(tree[idx].r, (a + b) / 2 + 1, b, l, r);
    } else {
        cover(tree[idx].r, (a + b) / 2 + 1, b, (a + b) / 2 + 1, r);
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int o = 0;
        cin >> o;

        if (o == 1) {
            int x = 0;
            int y = 0;
            cin >> x >> y;

            num[++idx] = x;
            num2[idx] = y;
            f[idx] = idx;

            Union(tmp, -1e9, 1e9, x);
            Union(tmp, -1e9, 1e9, y);

            if (num[idx] < num2[idx] - 1) {
                cover(tmp, -1e9, 1e9, num[idx] + 1, num2[idx] - 1);
            }
        } else {
            int a = 0;
            int b = 0;
            cin >> a >> b;

            int fa = find(a);
            int fb = find(b);
            if (fa == fb || (num[fb] < num[fa] && num[fa] < num2[fb]) || (num[fb] < num2[fa] && num2[fa] < num2[fb])) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }

	return 0;
}