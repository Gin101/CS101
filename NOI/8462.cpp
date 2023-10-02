#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1e5 + 1;
int dp[maxN][2] = {{0}};

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        memset(dp, 0, sizeof(dp));

        for (int j = 1; j <= n; j++) {
            int a = 0;
            cin >> a;

            dp[j][1] = dp[j - 1][0] + a;
            dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]);
        }

        cout << max(dp[n][0], dp[n][1]) << endl;
    }

    return 0;
}