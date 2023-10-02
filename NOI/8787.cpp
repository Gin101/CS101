#include <iostream>

using namespace std;

const int maxN = 201;
const int maxK = 7;
int dp[maxN][maxK] = {{0}};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i && j <= k; j++) {
            if (j == 1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            }
        }
    }

    cout << dp[n][k] << endl;

    return 0;
 } 