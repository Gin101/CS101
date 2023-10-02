#include <iostream>
#include <limits.h>
#include <stdio.h>

using namespace std;

const int maxN = 1000;
int d[maxN] = {0};
int c[maxN] = {0};
int s[maxN] = {0};
int w[maxN] = {0};
int dp[maxN] = {0};
int g[maxN][maxN] = {{0}};
int num[maxN][maxN] = {{0}};
int main()
{
    // freopen("valley.in", "r", stdin);
    // freopen("valley.out", "w", stdout);

    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 2; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> w[i];
    }

    for (int i = 1; i < n; i++) {
        g[i][i] = c[i];
        for (int j = i + 1; j <= n; j++) {
            for (int l = i + 1; l < j; l++) {
                if (d[l] - d[i] > s[l] && d[j] - d[l] > s[l]) {
                    g[i][j] += w[l];
                }
            }
            g[i][j] += c[i];
        }
    }
	
	for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (d[j] - d[i] > s[j]) {
                num[i][n] += w[j];
            }
        }
	}

    g[n][n] = c[n];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (d[i] - d[j] > s[j]) {
                dp[i] += w[j];
            }
        }
        dp[i] += c[i];
    }

    int result = INT_MAX;
    for (int i = 2; i <= k; i++) {
        for (int j = n; j >= i; j--) {
            for (int l = i - 1; l < j; l++) {
                if (l == i - 1) {
                    dp[j] = dp[l] + g[l][j];
                } else {
                    dp[j] = min(dp[j], dp[l] + g[l][j]);
                }
            }
            result = min(result, dp[j] + num[j][n]);
        }
    }
	
    cout << result << endl;
    
	return 0;
}