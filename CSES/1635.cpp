#include <iostream>

using namespace std;

const int maxN = 100;
const int maxX = 1e6 + 1;
const int MOD = 1e9 + 7;
int c[maxN] = {0};
int dp[maxX] = {0};

int main()
{
    int n = 0;
    int x = 0;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] <= i && dp[i - c[j]]) {
                dp[i] = (dp[i] + dp[i - c[j]]) % MOD;
            }
        }
    }

    cout << dp[x] % MOD << endl;

    return 0;
}