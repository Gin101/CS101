#include <iostream>

using namespace std;

const int maxM = 1001;
const int MOD = 1e9 + 7;
int dp[maxM] = {0};
int main()
{
    int n = 0;
    int m = 0;
    scanf("%d %d\n", &n, &m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[j + 1] = getchar() == '.' ? (dp[j + 1] + dp[j] + (i + j == 0)) % MOD : 0;
        }
    }

    cout << dp[m] << endl;

    return 0;
}