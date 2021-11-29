#include <iostream>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
int w[1 << 7] = {0};
struct Matrix {
	long long num[1 << 7][1 << 7] = {{0}};
	void init() {
        memset(num, 0, sizeof(num));
    }
}tmp, result2;
int dp[8][2] = {{0}};
Matrix power(Matrix x, Matrix y, int n) {
	Matrix result;
    result.init();
	for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (1 << n); j++) {
            for (int k = 0; k < (1 << n); k++) {
                (result.num[i][j] += x.num[i][k] * y.num[k][j] % MOD) %= MOD;
            }
        }
    }

	return result;
}
int ope(int s, int t, int n, int m) {
	dp[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
		if (((s & (1 << (i - 1))) || i > n) && (t & (1 << (i - 1)))) {
            dp[i][1] = dp[i - 1][0];
        } else {
            dp[i][1] = dp[i][0];
        }
	}

	return dp[m][1];
}
int main()
{
	for (int i = 1; i <= 7; i++) {
        cin >> w[i];
    }

	result2.num[0][0] = 1;
    int idx = 0;
	for (int i = 1; i <= 7; i++) {
		if (!w[i]) {
            continue;
        }
		for (int j = 0; j < (1 << idx); j++) {
            for (int k = 0; k < (1 << i); k++) {
                tmp.num[j][k] = ope(j, k, idx, i);
            }
        }

		result2 = power(result2, tmp, i);
        w[i]--;
        idx = i;

        for (int j = 0; j < (1 << i); j++) {
            for (int k = 0; k < (1 << i); k++) {
                tmp.num[j][k] = ope(j,k,i,i);
            }
        }

        while (w[i]) {
            if (w[i] & 1) {
                result2 = power(result2, tmp, i);
            }
            tmp = power(tmp, tmp, i);
            w[i] >>= 1;
        }
	}

    cout << result2.num[0][(1 << idx) - 1] << endl;

	return 0;
}