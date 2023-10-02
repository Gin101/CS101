#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 3e5 + 1;
long long dp[maxN][2] = {{0}};
int x[maxN] = {0};
long long y[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i <= n; i++) {
        if (x[i] == 1) {
            dp[i][1] = max(dp[i - 1][0] + y[i], dp[i - 1][1]);
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][0] + y[i], dp[i - 1][1] + y[i]));
            dp[i][1] = dp[i - 1][1];
        }
    }

    cout << max(dp[n][0], dp[n][1]) << endl;

    return 0;
}