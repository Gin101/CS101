#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 2001;
int e[maxN][maxN] = {{0}};
bool flag[maxN] = {false};
int dp[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    memset(dp, 0x3f3f3f3f, sizeof(dp));
    for (int i = 0; i < m; i++) {
        int p = 0;
        int u = 0;
        int v = 0;
        int w = 0;
        cin >> p >> u >> v >> w;

        if (p == 1) {
            if (flag[u]) {
                dp[v] = w;
                flag[v] = true;
            } else {
                dp[u] = w;
                flag[u] = true;
            }
        }

        e[u][v] = min(w, e[u][v]);
        e[v][u] = min(w, e[v][u]);  
    }

    if (dp[1] == 0x3f3f3f3f) {
        dp[1] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (dp[i] == 0x3f3f3f3f) {
            int idx = 0;
            for (int j = 1; j <= n; j++) {
                if (!flag[j] && dp[j] <= dp[idx]) {
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
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += dp[i];
        cout << dp[i] << ' ';
    }

    cout << result << endl;

    return 0;
}