#include <iostream>
#include <algorithm>

using namespace std;

#define int long long 

const int maxN = 2e5 + 1;
int dp[3][maxN] = {0};
int c[3] = {0};
signed main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int t = 0;
        int x = 0;
        cin >> t >> x;

        dp[t][++c[t]] = x;
    }

    for (int i = 0; i <= 2; i++) {
        sort(dp[i] + 1, dp[i] + c[i] + 1, greater<int>());
    }
    for (int i = 0; i <= 2; i++) {
        for (int j = 1; j <= c[i]; j++) {
            dp[i][j] += dp[i][j - 1];
        }
    }
	
    int result = 0;
    for (int i = 0; i <= c[1]; i++) {
        int tmp = lower_bound(dp[2], dp[2] + c[2] + 1, i) - dp[2];
        if (tmp <= c[2] && i + tmp <= m) {
            result = max(result, dp[1][i] + dp[0][min(m - i - tmp, c[0])]);
        }
    }
    
    cout << result << endl;
	
	return 0;
}
