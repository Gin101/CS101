#include <iostream>

using namespace std;

const int maxN = 1e6 + 1;
const int MOD = 1e9 + 7;
long long dp[maxN][2] = {{0}};

int main()
{
    int t = 0;
    cin >> t;

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < maxN; i++) {
        dp[i][0] = ((dp[i - 1][0] * 4) % MOD + dp[i - 1][1]) % MOD;
        dp[i][1] = ((dp[i - 1][1] * 2) % MOD + dp[i - 1][0]) % MOD;
    }

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        cout << (dp[n][0] + dp[n][1]) % MOD << endl;
    }

    return 0;
}