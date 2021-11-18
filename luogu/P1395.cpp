#include <iostream>
#include <vector>

using namespace std;

const int maxN = 5e4;
vector<int> e[maxN];
bool flag[maxN] = {false};
int num[maxN] = {0};//the size of subtree of i
int dp[maxN] = {0};

int dfs(int u) {
    for (int i = 0; i < e[u].size(); i++) {
        num[u] += dfs(e[u][i]);
    }

    return num[u];
}

int main()
{
    int n = 0;
    cin >> n;

    flag[0] = true;
    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        if (flag[u - 1]) {
            flag[v - 1] = true;
            e[u - 1].push_back(v - 1);
        } else {
            flag[u - 1] = true;
            e[v - 1].push_back(u - 1);
        }
    }

    dfs(0);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            dp[i] = dp[e[i][j]] + n - num[i] * 2;
        }
    }

    cout << dp[n] << endl;

    return 0;
}