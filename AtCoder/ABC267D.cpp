#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 2001;
const int maxM = 2001;
long long a[maxN] = {0};
long long dp[maxN][maxM] = {{0}};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = LONG_MIN;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i && j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i] * j);
        }
    }

    cout << dp[n][m] << endl;

    return 0;
}