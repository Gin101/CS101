#include <iostream>
#include <algorithm>

using namespace std;

const int maxM = 26;
const int maxN = 30000;
int v[maxM] = {0};
int w[maxM] = {0};
int dp[maxM][maxN] = {{0}};// dp[i][j] means from 1 to i, bag is j

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> v[i] >> w[i];
        w[i] *= v[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (j >= v[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[m][n] << endl;

    return 0;
}