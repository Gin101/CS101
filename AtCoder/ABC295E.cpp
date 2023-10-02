#include <iostream>

using namespace std;

#define int long long

const int maxN = 2001;
const int MOD = 998244353;
int a[maxN] = {0};
int dp[maxN][maxN] = {{0}};

int power(int x, int y) {
    return y ? power(x * x % MOD, y / 2) * (y % 2 ? x : 1) % MOD : 1;
}
signed main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    dp[0][0] = 1;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (a[i] == 0) {
            cnt++;
        }
        dp[i][0] = 1;

        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
        }
    }
	
    int result = 0;
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        tmp = n - cnt;
        for (int j = 1; j <= n; j++) {
            if (a[j] > i) {
                tmp--;
            }
        }
        for (int j = 0; j < k - tmp && j <= cnt; j++) {
            result = (result + dp[cnt][j] * power(i, j) % MOD * power(m - i, tmp - j)) % MOD;
        }
    }
	
    cout << result * power(m, MOD - 1 - cnt) % MOD << endl;

	return 0;
}
