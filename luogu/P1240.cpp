#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 201;
const int MOD = 504;
int g[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    if (k > 2 * n - 1) {
        cout << 0 << endl;
        return 0;
    }

	for (int i = 1; i < n; i++) {
        g[2 * i - 1] = g[2 * i] = 2 * i - 1;
    }

	g[2 * n - 1] = 2 * n - 1;

    for (int i = 0; i <= 2 * n - 1; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= 2 * n - 1; i++) {
        for (int j = 1; j <= g[i]; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * (g[i] - j + 1)) % MOD;
        }
    }
	
    cout << dp[2 * n - 1][k] << endl;
    
	return 0;
}
