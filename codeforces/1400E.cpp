#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 5001;
int a[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            dp[i - 1][j] = a[j] < a[i] ? min(dp[i][j] + 1, dp[i][i] + a[i] - a[j]) : dp[i][i];
        }
    }

    cout << dp[0][0] << endl;

    return 0;
}