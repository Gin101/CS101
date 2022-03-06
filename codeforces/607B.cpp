#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 501;
int a[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int main()
{
    int n = 0;
    cin >> n;

    memset(dp, 0x3f3f3f3f, sizeof(dp));
	for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

	for (int i = 1; i <= n; i++) {
        dp[i][i - 1] = 1;
        dp[i][i] = 1;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; i + j <= n; j++) {
            if (a[j] == a[i + j]) {
                dp[j][i + j] = dp[j + 1][i + j - 1];
            }
            for (int k = j; k < i + j; k++) {
                dp[j][i + j] = min(dp[j][i + j], dp[j][k] + dp[k + 1][i + j]);
            }
        }
    }

    cout << dp[1][n] << endl;

	return 0;
}