#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 10001;
const int maxM = 1001;
int x[maxN] = {0};
int y[maxN] = {0};
int p[maxN] = {0};

int dp[maxM][maxN] = {0};
bool g[maxM][maxN] = {{false}};
const int INF = 0x3f3f3f3f;

int main()
{
    int n = 0;//n means col
    int m = 0;//m means row
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    int now = 1;
    for (int i = 1; i <= k; i++) {
        int l = 0;
        int h = 0;
        cin >> p[i] >> l >> h;
        
        if (now + l >= m) {
            now -= h;
        } else {
            now += l;
        }
    }

    memset(dp, INF, sizeof(dp)); 
    for (int i = 0; i <= m; i++) {
        dp[i][0] = 0;
    }

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!g[j][i]) {
                if (j >= y[i] && g[j - y[i]][i]) {
                    dp[j][i] = min(dp[j][i], dp[j - y[i]][i]);
                }

                if (j + x[i] <= m && g[j + x[i]][i]) {
                    dp[j][i] = min(dp[j][i], dp[j + x[i]][i] + 1);
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (dp[m][n] != -1) {
            result = min(result, dp[m][n]);
        }
    }

    if (result < INT_MAX) {
        cout << 1 << endl << result << endl;
    } else {
        cout << 0 << endl;
        int tmp = 0;
        for (int i = m - 1; i >= 1; i--) {
            for (int j = 0; j <= n; j++) {
                if (dp[i][j] != INF) {
                    tmp = i;
                    break;
                }
            }
        }

        for (int i = 1; i <= k; i++) {
            if (p[i] > tmp) {
                cout << i - 1 << endl;
                break;
            }
        }
    }


    return 0;
}