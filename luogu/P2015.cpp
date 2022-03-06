#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n = 0;
const int maxN = 101 ;
int dp[maxN][maxN] = {{0}}; // dp[i][j] = the tree that its root is i and have j nodes max val
bool flag[maxN] = {false};
int son[maxN][maxN] = {0};
int tmp[maxN] = {0};
int e[maxN][maxN] = {{0}};

void dfs(int u) {
    for (int i = 1; i <= n && !son[u][0]; i++) {
        if (e[u][i] != -1) {
            son[u][0] = i;
            tmp[i] = e[u][i];
            e[u][i] = -1;
            e[i][u] = -1;
            dfs(i);
        }
    }

    for (int i = 1; i <= n && !son[u][1]; i++) {
        if (e[u][i] != -1) {
            son[u][1] = i;
            tmp[i] = e[u][i];
            e[u][i] = -1;
            e[i][u] = -1;
            dfs(i);
        }
    }
}

int ope(int u, int x) {
    if (dp[u][x]) {
        return dp[u][x];
    }

    if (!x) {
        return 0;
    }

    if (!son[u][0] && !son[u][1]) {
        return tmp[u];
    }

    for (int i = 0; i < x; i++) {
        dp[u][x] = max(dp[u][x], ope(son[u][0], i) + ope(son[u][1], x - i - 1) + tmp[u]);
    }

    return dp[u][x];
}

int main()
{
    int q = 0;
    cin >> n >> q;

    memset(e, -1, sizeof(e));
    for (int i = 1; i < n; i++) {
        int idx1 = 0;
        int idx2 = 0;
        int apple = 0;
        cin >> idx1 >> idx2 >> apple;

        e[idx1][idx2] = apple;
        e[idx2][idx1] = apple;
    }

    dfs(1);

    cout << ope(1, q + 1) << endl;

    return 0;
}