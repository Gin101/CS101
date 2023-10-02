#include <iostream>

using namespace std;

const int maxN = 101;
const int maxX = 1e6 + 1;
const int MOD = 1e9 + 7;
int c[maxN] = {0};
int dp[maxN][maxX] = {{0}};

int main() 
{

    int n = 0;
    int x = 0;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= x; j++) {
            dp[i][j] = dp[i - 1][j];
            if (j - c[i - 1] >= 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - c[i - 1]]) % MOD;
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}