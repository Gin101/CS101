#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 5e5 + 11;
const int INF = 0x3f3f3f3f;
int n = 0;
int m = 0;
int dp[maxN] = {0};
int sum[maxN] = {0};
int tmp[maxN * 4] = {0};

int main()
{
    int n = 0;
    int m = 0;
    while (cin >> n >> m) {
        for (int i = 1; i <= n; i++) {
            int c = 0;
            cin >> c;
            sum[i] = sum[i - 1] + c;
        }

        memset(dp, INF, sizeof(dp));
        dp[0] = 0;
        int l = 1;
        int r = 0;
        tmp[r = 1] = 0;
        for (int i = 1; i <= n; i++) {
            while (l < r && 2 * sum[i] * sum[tmp[l + 1]] - sum[tmp[l]] > dp[tmp[l + 1]] + sum[tmp[l + 1]] * sum[tmp[l + 1]] - dp[tmp[l]] - sum[tmp[l]] * sum[tmp[l]]) {
                l++;
            }
            dp[i] = dp[tmp[l]] + (sum[i] - sum[tmp[l]]) * (sum[i] - sum[tmp[l]]) + m;
            while (l < r && (dp[r] + sum[r] * sum[r] - dp[i] - sum[i] * sum[i]) * (sum[tmp[r - 1]] - sum[tmp[r]]) <= (sum[tmp[r] - sum[i]]) * (dp[tmp[r - 1]] + sum[tmp[r - 1]] * sum[tmp[r - 1]] - dp[tmp[r]] - sum[tmp[r]] * sum[tmp[r]])) {
                r--;
            }
            tmp[++r] = i;
        }
        
        cout << dp[n] << endl;
    }

    return 0;
}