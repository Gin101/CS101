#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 5e5 + 1;
int val[maxN] = {0};
int dp[maxN] = {0};
int result[maxN] = {0};
int tmp[maxN] = {0};
vector<int> e[maxN];

bool cmp(int x, int y) {
    return result[x] - dp[x] < result[y] - dp[y];
}

void dfs(int u, int pre) {
    if (u != 1) {
        dp[u] = val[u];
    }
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != pre) {
            dfs(e[u][i], u);
        }
    }

    int idx = 0;
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != pre) {
            tmp[++idx] = e[u][i];
        }
    }
    sort(tmp + 1, tmp + idx + 1, cmp);

    for (int i = 1; i <= idx; i++) {
        dp[u] = max(dp[u], dp[tmp[i]] + result[u] + 1);
        result[u] += result[tmp[i]] + 2;
    }

}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }

	dfs(1, 0);

    cout << max(dp[1], result[1] + val[1]) << endl;

	return 0;
}