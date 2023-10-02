#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 6001;
vector<int> e[maxN];
bool vis[maxN] = {false};
bool flag[maxN] = {false};
int dp[maxN][2] = {{0}};

void ope(int u) {
    vis[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        if (!vis[e[u][i]]) {
            ope(e[u][i]);
            dp[u][0] += max(dp[e[u][i]][0], dp[e[u][i]][1]);
            dp[u][1] += dp[e[u][i]][0];
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][1];
    }

    for (int i = 0; i < n - 1; i++) {
        int l = 0;
        int k = 0;
        cin >> l >> k;

        e[k].push_back(l);
        flag[l] = true;
    }

    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            ope(i);
            cout << max(dp[i][1], dp[i][0]) << endl;
            return 0;
        }
    }

    return 0;
}