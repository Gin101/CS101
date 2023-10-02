#include <iostream>

using namespace std;

const int maxM = 13;
const int maxN = 13;
const int MOD = 1e9;
int field[maxM][maxN] = {{0}};
int num[maxM] = {0};
int dp[maxM][1 << maxN] = {{0}};
bool flag[1 << maxN] = {false};
int main()
{
    int m = 0;
    int n = 0;
    cin >> m >> n;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> field[i][j];
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            num[i] = (num[i] << 1) + field[i][j];
        }
    }


    int idx = 1 << n;
    for (int i = 0; i < idx; i++) {
        flag[i] = ((i & (i << 1)) == 0) && ((i & (i >> 1)) == 0);
    }

    dp[0][0] = 1;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < idx; j++) {
            if (flag[j] && ((j & num[i]) == j)) {
                for (int k = 0; k < idx; k++) {
                    if ((k & j) == 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][k]) % MOD;
                    }
                }
            }
        }
    }
    
    int result = 0;
    for (int i = 0; i < idx; i++) {
        result = (result + dp[m][i]) % MOD;
    }

    cout << result << endl;

    return 0;
}