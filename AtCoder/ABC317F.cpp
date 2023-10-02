#include <iostream>
#include <cstring>

using namespace std;

#define int long long
const int MOD = 998244353;
int n = 0;
int a = 0;
int b = 0;
int c = 0;
int result = 0;
int dp[62][2][2][2][2][2][2][11][11][11] = {{{{{{{{{{0}}}}}}}}}};
int dfs(int d, int o, int p, int q, int u, int v, int w, int x, int y, int z) {
    if (d < 0) {
        return o && p && q && x + y + z == 0;
    }

    int result = 1ll << d;
    int tmp = (n & result) > 0;
    int &r = dp[d][o][p][q][u][v][w][x][y][z];
    if (r != -1) {
        return r;
    }

    r = 0;
    for (int i = 0; i <= (tmp | u); i++) {
        for (int j = 0; j <= (tmp | v); j++) {
            for (int k = 0; k <= (tmp | w); k++) {
                if (i ^ j ^ k) {
                    continue;
                }
                r += dfs(d - 1, o | i, p | j, q | k, u || i < tmp, v || j < tmp, w || k < tmp, (x + result * i) % a, (y + result * j) % b, (z + result * k) % c);
            }
        }
    }

    return r %= MOD;
}
signed main()
{
    cin >> n >> a >> b >> c;
    
    memset(dp, -1, sizeof(dp));

    result =  dfs(60, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    cout << result << endl;

	return 0;
}