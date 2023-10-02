#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxE = 101;
const int maxD = 101;
const int INF = 0x3f3f3f3f;
int g[maxE][maxD] = {{0}};
int dp[maxN][maxD] = {{0}};

int main()
{
    int n = 0;
    int e = 0;
    int d = 0;
    cin >> n >> e >> d;

    if (e < d) {
        cout << 0 << endl;
        return 0;
    }

    memset(g, INF, sizeof(g));
    for (int i = 0; i <= e; i++) {
        g[i][0] = 0;
    }

    for (int i = 1; i <= e; i++) {
        for (int j = 1; j <= d; j++) {
            for (int k = 1; k <= j && k * k <= i; k++) {
                g[i][j] = min(g[i][j], g[i - k * k][j - k] + 1);
            }
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= d; j++) {
            for (int k= 0; k <= j; k++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - k] + g[e - d + j][k]);
            }
        }
    }

    cout << dp[n][d] << endl;

    return 0;
}