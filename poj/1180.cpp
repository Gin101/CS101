#include <iostream>

using namespace std;

const int maxN = 10002;
int t[maxN] = {0};
int f[maxN] = {0};
int tmp[maxN] = {0};
int dp[maxN] = {0};

int main()
{
    int n = 0;
    int s = 0;
    cin >> n >> s;

    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> f[i];
    }

    for (int i = n; i >= 1; i--) {
        t[i] += t[i + 1];
        f[i] += f[i + 1];
    }

    int l = 0;
    int r = 0;
    tmp[0] = n + 1;
    for (int i = n; i >= 1; i--) {
        while (l < r && dp[tmp[l + 1]] - dp[tmp[l]] <= (t[tmp[l + 1]] - t[tmp[l]]) * f[i]) {
            l++;
        }
        dp[i] = dp[tmp[l]] + (t[i] - t[tmp[l]] + s) * f[i];
        while (l < r && (dp[i] - dp[tmp[r]]) * (t[tmp[r]] - t[tmp[r - 1]]) <= (t[i] - t[tmp[r]]) * (dp[tmp[r]] - dp[tmp[r - 1]])) {
            r--;
        }
        tmp[++r] = i;
    }

    cout << dp[1] << endl;

    return 0;
}