#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 301;
int e[maxN][maxN] = {{0}};
bool flag[maxN] = {false};
int dp[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        int c = 0;
        cin >> u >> v >> c;

        e[u][v] = c;
        e[v][u] = c;  
    }

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 0; i < n; i++) {
        int idx = 0;
        for (int j = 1; j <= n; j++) {
            if (!flag[j] && dp[j] < dp[idx]) {
                idx = j;
            }
        }

        flag[idx] = true;

        for (int j = 1; j <= n; j++) {
            if (!flag[j] && e[idx][j] != 0 && e[idx][j] < dp[j]) {
                dp[j] = e[idx][j];
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = max(result, dp[i]);
    }

    cout << n - 1 << ' ' << result << endl;

    return 0;
}