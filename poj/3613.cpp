/*
dp[i][x][y] 表示
dp[2a][x][y] = min(dp[a][x][z] + dp[a][z][y])
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 1e6 + 1;
const int maxT = 101;
const int INF = 0x3f3f3f3f;
int num[maxN] = {0};
int cnt = 0;
struct Map {
    int dp[maxT * 2][maxT * 2];
    Map operator* (const Map x) {
        Map tmp;
        memset(tmp.dp, INF, sizeof(tmp.dp));
        for (int i = 1; i <= cnt; i++) {
            for (int j = 1; j <= cnt; j++) {
                for (int k = 1; k <= cnt; k++) {
                    tmp.dp[j][k] = min(tmp.dp[j][k], dp[j][i] + x.dp[i][k]);
                }
            }
        }

        return tmp;		
    }
} dis, result;
int main()
{
    int n = 0;
    int t = 0;
    int s = 0;
    int e = 0;
    cin >> n >> t >> s >> e;

    memset(dis.dp, INF, sizeof(dis.dp));
    for (int i = 1; i <= t; i++) {
        int w = 0;
        int u = 0;
        int v = 0;
        cin >> w >> u >> v;

        if (num[u] == 0) {
            num[u] = ++cnt;
        } 
        if (num[v] == 0) {
            num[v] = ++cnt;
        }

        dis.dp[num[u]][num[v]] = w;
        dis.dp[num[v]][num[u]] = w;
    }

    n--;
    result = dis;
    while (n != 0) {
        if (n & 1) {
            result = result * dis;
        }

        dis = dis * dis;

        n >>= 1;
    }

    cout << result.dp[num[s]][num[e]] << endl;

    return 0;
}