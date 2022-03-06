#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2001;
int n = 0;
int k = 0;
int num[maxN] = {0};
long long dp[maxN][maxN] = {0};
vector<pair<int, int> > e[maxN];
void dfs(int u, int pre) {
    num[u] = 1;
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i].first == pre) {
            continue;
        }

        dfs(e[u][i].first, u);
        for (int j = min(num[u] + num[e[u][i].first], k); j >= 0; j--) {
            for (int l = max(j - num[u], 0); l <= num[e[u][i].first] && l <= j; l++) {
                dp[u][j] = max(dp[u][j], dp[u][j - l] + dp[e[u][i].first][l] + 1ll * l * (k - l) * e[u][i].second + 1ll * (num[e[u][i].first] - l) * (n - num[e[u][i].first] - k + l) * e[u][i].second);
            } 
        }

        num[u] += num[e[u][i].first];
    }
}
int main() 
{
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        int t = 0;
        cin >> u >> v >> t;

        e[u].push_back(make_pair(v, t));
        e[v].push_back(make_pair(u, t));
    }

    dfs(1, 0);

    cout << dp[1][k] << endl;

    return 0;
}