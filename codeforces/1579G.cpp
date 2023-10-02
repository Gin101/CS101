#include <iostream>
#include <algorithm>
#include <cstring>
#include <limits.h>

using namespace std;

const int maxA = 1001;
const int maxN = 1e4 + 1;
int a[maxN] = {0};
int dp[maxA * 3] = {0};
int dp2[maxA * 3] = {0};

int main() 
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t = 0;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int idx = 0;
        for (int j = 0; j < n; j++) {
            cin >> a[j];
            idx = max(idx, a[j] * 2);
        }

        memset(dp, 1, sizeof(dp));
        dp[0] = 0;
        for (int j = 0; j < n; j++) {
            memset(dp2, 1, sizeof(dp2));
            for (int k = 0; k <= idx; k++) {
                dp2[max(0, k - a[j])] = min(dp2[max(0, k - a[j])], dp[k] + a[j]);
                dp2[k + a[j]] = min(dp2[k + a[j]], max(0, dp[k] - a[j]));
            }
            memcpy(dp, dp2, sizeof(dp));
        }

        int result = INT_MAX;
        for (int j = 0; j <= idx; j++) {
            result = min(result, j + dp[j]);
        }

        cout << result << endl;
    }
	
    return 0;
}