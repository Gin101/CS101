#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 100;
long long e[maxN][maxN] = {{0}};
long long dp[maxN][maxN] = {{0}};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    memset(e, 0x3f3f3f3f, sizeof(e));
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        int dist = 0;
        cin >> u >> v >> dist;

        e[u - 1][v - 1] = dist;
        e[v - 1][u - 1] = dist;
    }

    memcpy(dp, e, sizeof(e));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        if (dp[0][i] == 0x3f3f3f3f) {
            cout << -1 << endl;
        } else {
            result = max(result, dp[0][i]);
        }
    }

    cout << result << endl;

    return 0;
}