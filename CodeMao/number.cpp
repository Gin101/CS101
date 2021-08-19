#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxNM = 1000;
int num[maxNM][maxNM] = {{0}};
int dp[maxNM][maxNM] = {{0}};

int main()
{
    int n = 0;
    int m = 0;  
    // cin >> n >> m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < m; j++) {
            // cin >> num[i][j];
            scanf("%d", &num[i][j]);
        }
    }

    dp[0][0] = num[0][0];
    for(int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + num[i][0];
    }

    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            dp[j][i] = dp[j][i - 1] + num[j][i];
            int tmp = num[j][i];
            for (int k = j + 1; k < n; k++) {
                tmp += num[k][i];
                dp[j][i] = max(dp[j][i], dp[k][i - 1] + tmp);
            }

            tmp = num[j][i];
            for (int k = j - 1; k >= 0; k--) {
                tmp += num[k][i];
                dp[j][i] = max(dp[j][i], dp[k][i - 1] + tmp);
            }
        }
    }

    // cout << dp[n - 1][m - 1] << endl;
    printf("%d\n", dp[n - 1][m - 1]);

    return 0;
}