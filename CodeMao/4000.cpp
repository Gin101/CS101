#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 101;
int e[maxN][maxN] = {{0}};
bool flag[maxN] = {false};
int dp[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    int result = 0;
    for (int i = 0; i < k; i++) {
        int u = 0;
        int v = 0;
        int m = 0;
        cin >> u >> v >> m;

        e[u][v] = m;
        e[v][u] = m;  

        result += m;
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

    for (int i = 1; i <= n; i++) {
        result -= dp[i];
    }

    cout << result << endl;

    return 0;
}