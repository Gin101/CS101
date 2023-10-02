#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxN = 101;
const int maxP = 101;
const double INF = 0x3f3f3f3f;
int c[maxN] = {0};
int p[maxN] = {0};
int s[maxN][maxP] = {{0}};
double dp[maxN + maxP] = {0};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> p[i];
        for (int j = 1; j <= p[i]; j++) {
            cin >> s[i][j];
        }
    }

    for (int i = m - 1; i >= 0; i--) {
        dp[i] = INF;
        for (int j = 1; j <= m; j++) {
            for (int k = 1; k <= n; k++) {
                double tmp = 0;
                for (int l = 1; l <= p[k]; l++) {
                    tmp += dp[s[k][l] + i];
                }
                dp[i] = min(dp[i], c[k] + tmp / p[k]);
            }
        }
    }
	
    printf("%.5lf\n", dp[0]);

	return 0;
}