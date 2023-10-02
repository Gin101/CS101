#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 5e6 + 1;
long long sum[maxN] = {0};
long long dp[maxN][2] = {0};
long long q[maxN] = {0};
int main()
{
    freopen("garden.in", "r", stdin);
    freopen("garden.out", "w", stdout);

    long long n = 0;
    long long m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int e = 0;
        cin >> e;

        sum[i] = sum[i - 1] + e;
    }

    long long l = 1;
    long long r = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        while (q[l] < i - m && l <= r) {
            l++;
        }
        dp[i][1] = dp[q[l]][0] - sum[q[l]] + sum[i];
        while (dp[i][0] - sum[i] > dp[q[r]][0] - sum[q[r]]) {
            r--;
        }
        r++;
        q[r] = i;
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

	return 0; 
} 