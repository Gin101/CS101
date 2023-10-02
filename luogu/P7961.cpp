#include <iostream>

using namespace std;

const long long MOD = 998244353;

const int maxM = 105;
const int maxN = 35;
const int maxK = 35;
long long v[maxM] = {0};
long long dp[maxM][maxN][maxK][16] = {{{{0}}}};
long long idx[maxM][maxN] = {{0}};
long long cnt[maxN][maxN] = {{0}};
long long ope(int n) {
	int tmp = 0;
	while (n) {
        tmp += n & 1;
        n >>= 1;
    }
	return tmp;
}

int main() 
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;
	
    for (int i = 0; i <= n; i++) {
        cnt[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cnt[i][j] = (cnt[i - 1][j] + cnt[i - 1][j - 1]) % MOD;
        }
    }

	for (int i = 0; i <= m; i++) {
        cin >> v[i];

		idx[i][0] = 1;
        for (int j = 1; j <= n; j++) {
            idx[i][j] = idx[i][j - 1] * v[i] % MOD;
        }
	}

	dp[0][0][0][0] = 1;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int l = 0; l <= k; l++) {
                for (int o = 0; o <= n / 2; o++) {
                    for (int p = 0; p <= n - j; p++) {
                        dp[i + 1][j + p][l + (p + o & 1)][(p + o) / 2] = (dp[i + 1][j + p][l + (p + o & 1)][(p + o) / 2] + dp[i][j][l][o] * idx[i][p] % MOD * cnt[n - j][p] % MOD) % MOD;
                    }
                }
            }
        }
    }

    long long result = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n / 2; j++) {
            if (i + ope(j) <= k) {
                result = (result + dp[m + 1][n][i][j]) % MOD;
            }
        }
    }
	
    cout << result << endl;

	return 0;
}