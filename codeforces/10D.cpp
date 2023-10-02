#include <iostream>

using namespace std;

const int maxN = 501;
const int maxM = 501;
int n = 0;
int a[maxN] = {0};
int b[maxM] = {0};
int dp[maxN][maxM] = {0};
int g[maxN][maxM] = {0};

void dfs(int x) {
    if (x == 0) {
        return;
    }

    dfs(g[n][x]);
    cout << b[x] << ' ';
}

int main() 
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m = 0;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }

	a[0] = -1;
    b[0] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                for (int k = 0; k < j; k++) {
                    if (a[i] > b[k] && dp[i][j] < dp[i - 1][k] + 1) {
                        dp[i][j] = dp[i - 1][k] + 1;
                        g[i][j] = k;
                    }
                }
            } else {
                dp[i][j] = dp[i - 1][j];
                g[i][j] = g[i - 1][j];
            }
        }
    }

    int idx = 0;
    for (int i = 1; i <= m; i++) {
        if (dp[n][idx] < dp[n][i]) {
            idx = i;
        }
    }

	cout << dp[n][idx] << endl;

    dfs(idx);

    cout << endl;

	return 0;
}