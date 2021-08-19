#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 2001;
const int maxNC = 60001;
int c[maxN] = {0};
int d[maxN] = {0};
int k[maxN] = {0};
int dp[maxN][maxNC] = {{0}};
int dp2[maxN][maxN] = {{0}};
const int INF = 0x3f3f3f3f;

int main()
{
    int n = 0;
    int m = 0;
    int v = 0;
    int e = 0;
    cin >> n >> m >> v >> e;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        cin >> k[i];
    }

    memset(dp, INF, sizeof(dp));
    for (int i = 0; i <= n * v; i++) {
        dp[0][i] = 0;
    }

    dp[1][c[1]] = 0;
    dp[1][d[1]] = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= n * v; j++) {

        }
    }

    return 0;
}