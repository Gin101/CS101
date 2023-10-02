#include <iostream>

using namespace std;

const int maxN = 51;
long long dp[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    dp[0] = 1;
    for (int i = 1; i <= m; i++) {
        dp[i] = 2 * dp[i - 1];
    }
    dp[m]--;

    for (int i = m + 1; i <= n; i++) {
        dp[i] = 2 * dp[i - 1] - dp[i - m - 1];
    }

    cout << dp[n] << endl;

    return 0;
}