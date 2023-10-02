#include <iostream>

using namespace std;

const int maxN = 101;
const int INF = 0x3f3f3f3f;
int m[maxN] = {0};
int p[maxN] = {0};
int dp[maxN] = {0};
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int w = 0;
        cin >> n >> w;

        for (int j = 1; j <= n; j++) {
            cin >> m[j];
        }
        m[0] = -INF;

        for (int j = 1; j <= n; j++) {
            cin >> p[j];
        }

        dp[0] = 0;
        for (int j = 1; j <= n; j++) {
            dp[j] = max(dp[j - 1], p[j]);
            for (int k = 1; k < j; k++) {
                if (m[j] - m[k] > w) {
                    dp[j] = max(dp[j], dp[k] + p[j]);
                } else {
                    break;
                }
            }
        }

        cout << dp[n] << endl;
    }

    return 0;
}