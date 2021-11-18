#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 1001;
int a[maxN] = {0};
int dp[maxN][maxN] = {{0}};
const int INF = 0x3f3f3f3f;
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n; j++) {
            int sum = 0;
            for (int k = i; k <= j; k++) {
                sum += a[k];
            }
            for (int k = i; k < j; k++) {
                dp[j][j + i] = min(dp[j][j + i], dp[i][k] + dp[k + 1][j]) + sum;
            }
        }
    }

    cout << dp[1][n] << endl;

    return 0;
}