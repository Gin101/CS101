#include <iostream>

using namespace std;

const int maxN = 1001;
const int INF = 0x3f3f3f3f;
int dp[maxN][maxN][2] = {{0}};
char g[maxN][maxN][2];
int num = 0;
void print(int x, int y) {
    if (x == 1 && y == 1) {
        return;
    }
    if (g[x][y][num]) {
        print(x - 1, y);
        cout << 'D';
    } else {
        print(x, y - 1);
        cout << 'R';
    }
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 2; i <= n; i++) {
        dp[0][i][0] = INF;
        dp[0][i][1] = INF;
        dp[i][0][0] = INF;
        dp[i][0][1] = INF;
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num;
            if (num) {
                while (num % 2 == 0) {
                    dp[i][j][0]++;
                    num /= 2;
                }
                while (num % 5 == 0) {
                    dp[i][j][1]++;
                    num /= 5;
                }
            } else {
                idx = i;
            }
           
            for (int k = 0; k < 2; k++) {
                g[i][j][k] = dp[i - 1][j][k] < dp[i][j - 1][k];
                if (g[i][j][k]) {
                    dp[i][j][k] += dp[i - 1][j][k];
                } else {
                    dp[i][j][k] += dp[i][j - 1][k];
                }
            }
		}
    }

    num = dp[n][n][1] < dp[n][n][0];
    if (idx && dp[n][n][num] > 1) {
        cout << 1 << endl;
        for (int i = 2; i <= idx; i++) {
            cout << 'D';
        }
        for (int i = 2; i <= n; i++) {
            cout << 'R';
        }
        for (int i = idx + 1; i <= n; i++) {
            cout << 'D';
        }
    } else {
        cout << dp[n][n][num] << endl;
        print(n, n);
    }

    cout << endl;

    return 0;
}