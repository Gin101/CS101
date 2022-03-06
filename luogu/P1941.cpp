#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e4 + 1;
const int INF = 0x3f3f3f3f;
int x[maxN] = {0};
int y[maxN] = {0};
int dp[2][maxN] = {{0}};
int l[maxN] = {0};
int h[maxN] = {0};
int cnt[maxN << 4] = {0};
int main() 
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        l[i] = 0;
        h[i] = m + 1;
    }

    for (int i = 0; i < k; i++) {
        int p = 0;
        int l2 = 0;
        int h2 = 0;
        cin >> p >> l2 >> h2;
        
        l[p] = l2;
        h[p] = h2;
        cnt[p]++;
    }

    dp[0][0] = INF;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[idx ^ 1][j] = INF;
        }

        for (int j = 1; j < min(h[i], m); j++) {
            if (j > x[i - 1]) {
                dp[idx ^ 1][j] = min(dp[idx][j - x[i - 1]], dp[idx ^ 1][j - x[i - 1]]) + 1;
            }
        }

        for (int j = l[i] + 1; j <= min(h[i] - 1, m - y[i - 1]); j++) {
            dp[idx ^ 1][j] = min(dp[idx ^ 1][j], dp[idx][j + y[i - 1]]);
        }

        if (h[i] > m) {
            for (int j = 1; j <= m; j++) {
                dp[idx ^ 1][m] = min(dp[idx ^ 1][m], dp[idx][j] + max(1, (m - j + x[i - 1] - 1) / x[i - 1]));
            }
        }

        bool flag = false;
        for (int j = l[i] + 1; j < h[i]; j++) {
            if (dp[idx ^ 1][j] < INF) {
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << 0 << endl << cnt[i - 1] << endl;
            return 0;
        }

        cnt[i] += cnt[i - 1];
        idx ^= 1;
        for (int j = 1; j <= l[i]; j++) {
            dp[idx][j] = INF;
        }
    }

    int result = INF;
    for (int i = 1; i <= m; ++i) {
        result = min(result, dp[idx][i]);
    }

    cout << 1 << endl << result << endl;
}