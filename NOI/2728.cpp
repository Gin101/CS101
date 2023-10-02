#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxR = 101;
const int maxC = 101;
int m[maxR][maxC] = {{0}};
int dp[maxR][maxC] = {{0}};
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int r = 0;
        int c = 0;
        cin >> r >> c;

        for (int j = 1; j <= r; j++) {
            for (int k = 1; k <= c; k++) {
                cin >> m[j][k];
            }
        }

        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= r; j++) {
            for (int k = 1; k <= c; k++) {
                if (j == 1) {
                    dp[j][k] = dp[j][k - 1] + m[j][k];
                } else if (k == 1) {
                    dp[j][k] = dp[j - 1][k] + m[j][k];
                } else {
                    dp[j][k] = max(dp[j - 1][k], dp[j][k - 1]) + m[j][k];
                }
            }
        }

        cout << dp[r][c] << endl;
    }

    return 0;
}