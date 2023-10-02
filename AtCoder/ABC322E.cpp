#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define ing long long

const int maxK = 15;
const int INF = 0x3f;
int a[maxK] = {0};
long long dp[1 << maxK] = {0};
signed main()
{
    int n = 0;
    int k = 0;
    int p = 0;
    cin >> n >> k >> p;

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int c = 0;
        cin >> c;

        for (int j = 1; j <= k; j++) {
            cin >> a[j];
        }
        for (int j = 32767; j >= 0; j--) {
            int idx = 0;
            for (int l = 0; l <= (k - 1) * 3; l += 3) {
                idx += (min(p, ((j >> l) & 7) + a[l / 3 + 1]) << l);
            }
            dp[idx] = min(dp[idx], dp[j] + c);
        }
    }
    
    int result = 0;
    for (int i = 0; i < k; i++) {
        result += (p << (i * 3));
    }
    if (dp[result] >= 1e18) {
        cout << -1 << endl;
    } else {
        cout << dp[result] << endl;
    }

    return 0;
}