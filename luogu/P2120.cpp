#include <iostream>

using namespace std;

const int maxN = 1e6 + 1;
long long x[maxN] = {0};
long long p[maxN] = {0};
long long c[maxN] = {0};
long long sump[maxN] = {0};
long long sum[maxN] = {0};
long long tmp[maxN] = {0};
long long dp[maxN] = {0};
double slope(int x, int y) {
    return 1.0 * (dp[x] + sum[x] - dp[y] - sum[y]) / (sump[x] - sump[y]);
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> p[i] >> c[i];
        sump[i] = sump[i - 1] + p[i];
        sum[i] = sum[i - 1] + x[i] * p[i];
    }

    int l = 0;
    int r = 0;
    for (int i = 1; i <= n; i++) {
        while (l < r && slope(tmp[l + 1], tmp[l]) < x[i]) {
            l++;
        }
        dp[i] = dp[tmp[l]] + x[i] * (sump[i] - sump[tmp[l]]) - sum[i] + sum[tmp[l]] + c[i];
        while (l < r && slope(tmp[r], tmp[r - 1]) > slope(i, tmp[r])) {
            r--;
        }
        tmp[++r] = i;
    }

    cout << dp[n] << endl;

    return 0;
}