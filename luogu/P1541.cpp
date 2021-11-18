#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 351;
const int maxM = 121;
const int maxNum = 41;
int a[maxN] = {0};
int dp[maxNum][maxNum][maxNum][maxNum] = {{{{0}}}};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int card1 = 0;
    int card2 = 0;
    int card3 = 0;
    int card4 = 0;
    for (int i = 1; i <= m; i++) {
        int b = 0;
        cin >> b;

        switch (b) {
            case 1: {
                card1++;
                break;
            } case 2: {
                card2++;
                break;
            } case 3: {
                card3++;
                break;
            } case 4: {
                card4++;
            }
        }
    }

    dp[0][0][0][0] = a[1];
    for (int i = 0; i <= card1; i++) {
        for (int j = 0; j <= card2; j++) {
            for (int k = 0; k <= card3; k++) {
                for (int l = 0; l <= card4; l++) {
                    int idx = 1 + i + 2 * j + 3 * k + 4 * l;
                    if (i != 0) {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i - 1][j][k][l] + a[idx]);
                    }
                    if (j != 0) {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j - 1][k][l] + a[idx]);
                    }
                    if (k != 0) {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k - 1][l] + a[idx]);
                    }
                    if (l != 0) {
                        dp[i][j][k][l] = max(dp[i][j][k][l], dp[i][j][k][l - 1] + a[idx]);
                    }
                }
            }
        }
    }

    cout << dp[card1][card2][card3][card4] << endl;

    return 0;
}