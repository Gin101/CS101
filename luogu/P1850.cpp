#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const int maxNM = 2001;
const double INF = 0x3f3f3f3f;
int a[maxNM] = {0};
int b[maxNM] = {0};
int d[301][301] = {{0}};
double dp[maxNM][maxNM][2] = {{{0}}};
double k[maxNM] = {0};
int main() 
{
    int n = 0;
    int m = 0;
    int v = 0;
    int e = 0;
    cin >> n >> m >> v >> e;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            d[i][j] = INF;
        }
        d[i][i] = 0;
    }
    
    for (int i = 0; i < e; i++) {
        int u = 0;
        int v = 0;
        int w = 0;
        cin >> u >> v >> w;

        d[u][v] = d[v][u] = min(d[u][v], w);
    }
    
    for (int i = 1; i <= v; i++) {
        for (int j = 1; j <= v; j++) {
            for (int k = 1; k <= v; k++) {
                d[j][k] = min(d[j][k], d[j][i] + d[i][j]);
            }
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[n][0][0] = dp[n][1][1] = 0;

    for (int i = n - 1; i > 0; i--) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = min(dp[i + 1][j][0] + d[a[i]][a[i + 1]], dp[i + 1][j][1] + k[i + 1] * d[a[i]][b[i + 1]] + (1 - k[i + 1]) * d[a[i]][a[i + 1]]);
            if (j != 0) {
                dp[i][j][1] = min(dp[i + 1][j - 1][0] + k[i] * d[b[i]][a[i + 1]] + (1 - k[i]) * d[a[i]][a[i + 1]], dp[i + 1][j - 1][1] + k[i] * k[i + 1] * d[b[i]][b[i + 1]] + k[i] * (1 - k[i + 1]) * d[a[i]][a[i + 1]]);
            }
        }
    }

    double result = INF;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= 1; j++) {
            result = max(result, dp[1][i][j]);
        }
    }

    printf("%.2lf\n", result);

    return 0;
}