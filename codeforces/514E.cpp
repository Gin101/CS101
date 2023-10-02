#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
int sz[maxN] = {0};
int f[maxN][20] = {{0}};
int d[maxN] = {0};
basic_string<int> g[maxN];
void dfs(int u, int fa) {
    d[u] = d[fa] + 1;
    f[u][0] = fa;
    sz[u] = 1;

    for (int i = 0; f[u][i]; i++) {
        f[u][i + 1] = f[f[u][i]][i];
    }

    for (int v : g[u]) {
        if (v != fa) {
            dfs(v, u);
            sz[u] += sz[v];
        }
    }
}

int lca(int x, int y) {
    if (d[x] < d[y]) {
        swap(x, y);
    }
    for (int i = 18; ~i; i--) {
        if (d[f[x][i]] >= d[y]) {
            x = f[x][i];
        }
    }

    if (x == y) {
        return x;
    }

    for (int i = 18; ~i; i--) {
        if (f[x][i] != f[y][i]) {
            x = f[x][i];
            y = f[y][i];
        }
    }

    return f[x][0];
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        g[x] += y;
        g[y] += x;
    }

    dfs(1, 0);
    int m = 0;
    cin >> m;

    while (m--) {
        int x = 0;
        int y= 0;
        if (d[x] + d[y] & 1) {
            cout << 0 << endl;
        } else {
            if (d[x] < d[y]) {
                swap(x, y);
            }
            int tmp = (d[x] + d[y]) / 2 - d[lca(x, y)] - 1;
            for (int i = 18; ~i; i--) {
                if ((tmp >> i) & 1) {
                    x = f[x][i];
                    y = f[y][i];
                }
            }

            if (d[x] != d[y]) {
                cout << sz[f[x][0]] - sz[x] << endl;
                continue;
            } else {
                cout << n - sz[x] - sz[y] << endl;
            }
        }
    }

    return 0;
}