#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 1001;
const int INF = 0x3f3f3f3f;
int dp[maxN][maxN] = {{0}};
int main() 
{
    int n = 0;
    int m = 0;
    int x = 0;
    cin >> n >> m >> x;

    memset(dp, INF, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int a = 0;
        int b = 0;
        int t = 0;
        cin >> a >> b >> t;

        dp[a][b] = min(dp[a][b], t);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }
    
    int result = 0;
    for (int i = 1; i <= n; i++) {
        result = max(result, dp[i][x] + dp[x][i]);
    }

    cout  << result << endl;

    return 0;
}