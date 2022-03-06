#include <iostream>

using namespace std;

const int maxN = 3001;
long long a[maxN] = {0};
long long dp[maxN][maxN] = {{0}};
long long sum[maxN][maxN] = {{0}};
int main()
{
    int n = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        sum[i][i] = a[i];
        for (int j = i + 1; j <= n; j++) {
            sum[i][j] = sum[i][j - 1] + a[j];
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][i] = a[i];
    }
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= n - i; j++) {
            dp[j][j + i] = sum[j][i + j] - min(dp[j][i + j - 1], dp[j + 1][i + j]);
        }
    }

    cout << dp[1][n] - (sum[1][n] - dp[1][n]) << endl;

    return 0; 
}