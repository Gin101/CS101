#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 2e5 + 1;
const int maxM = 4e5 + 1;
int monkey[maxN][2] = {{0}};
int f[maxN] = {0};
int q[maxM][2] = {{0}};
bool flag[maxN][2] = {{false}};
int result[maxN] = {0};
int e[maxN] = {0};
int _next[maxM] = {0};
int val[maxM] = {0};

int find(int x) {
    if (f[x] == x) {
        return x;
    } else {
        return f[x] = find(f[x]);
    }
}

void dfs(int x, int y, int pre) {
    result[x] = y;
    int idx = e[x];
    while (idx) {
        if (val[idx] != pre) {
            dfs(val[idx], y, x);
        }
        idx = _next[idx];
    }
}

int cnt = 0;
void add(int x, int y) {
    val[++cnt] = y;
    _next[cnt] = e[x];
    e[x] = cnt;
    val[++cnt] = x;
    _next[cnt] = e[y];
    e[y] = cnt;
}

void merge(int x, int y, int z) {
    if (y < 0 || find(x) == find(y)) {
        return;
    }

    if (f[x] == find(1)) {
        dfs(y, z, 0);
    } else if (f[y] == find(1)) {
        dfs(x, z, 0);
    } else {
        add(x, y);
    }
    f[f[x]] = f[y];
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &monkey[i][0], &monkey[i][1]);
        f[i] = i;
    }

    for (int i = 0; i < m; i++) {
        int l2 = 0;
        int r2 = 0;
        cin >> l2 >> r2;

        q[i][0] = l2;
        q[i][1] = r2 - 1;
        flag[l2][r2 - 1] = true;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 2; j++) {
            if (!flag[i][j]) {
                merge(i, monkey[i][j], -1);
            }
        }
    }

    for (int i = m - 1; ~i; i--) {
        merge(q[i][0], monkey[q[i][0]][q[i][1]], i);
    }

    cout << -1 << endl;
    for (int i = 2; i <= n; i++) {
        printf("%d\n", result[i]);
    }

    return 0;
}