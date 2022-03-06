#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 1002;
const int INF = 0x3f3f3f3f;
int a[maxN] = {0};
int b[maxN] = {0};
int dp[maxN][6 * maxN] = {{0}};

int main()
{
    int n = 0;
    cin >> n;

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i];
        sum += a[i] + b[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[1][a[1]] = 0;
    dp[1][b[1]] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= 6 * n; j++) {
            if (j - a[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - a[i]]);
            }
            if (j - b[i] >= 0) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - b[i]] + 1);
            }
        }
    }

    int tmp = INT_MAX;
    int result = INT_MAX;
    for (int i = 0; i <= sum; i++) {
        if (dp[n][i] != INF) {
            if (abs(i - (sum - i)) < tmp) {
                tmp = abs(i - (sum - i));
                result = dp[n][i];
            } else if (abs(i - (sum - i)) == tmp) {
                result = min(result, dp[n][i]);
            }
        }
    }

    cout << result << endl;

    return 0;
}