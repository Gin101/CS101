#include <iostream>

using namespace std;

const int maxN = 40;
const int maxS = 780;
int dp[maxN][maxS] = {{0}};

int main()
{
    int n = 0;
    cin >> n;

    int tmp = n * (n + 1) / 2;
    if (tmp % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }

    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= tmp; j++) {
            if (j > i) {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - i];
            } else {
                dp[i][j] = dp[i - 1][j];
            } 
        }
    }

    cout << dp[n][tmp / 2] << endl;

    return 0;
}