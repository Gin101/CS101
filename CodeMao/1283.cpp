
// floyd

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 100;
double e[maxN][maxN] = {{0}};
double dp[maxN][maxN] = {{0}};

struct Dot {
    int x = 0;
    int y = 0;
}p[maxN];
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int m = 0;
    cin >> m;

    memset(e, 0x7f, sizeof(e));//gigantic
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        int tmp = abs(p[u - 1].x - p[v - 1].x);
        int tmp2 = abs(p[u - 1].y - p[v - 1].y);
        e[u - 1][v - 1] = sqrt(tmp * tmp  + tmp2 * tmp2);
        e[v - 1][u - 1] = e[u - 1][v - 1];
    }

    memcpy(dp, e, sizeof(e));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[j][k] = min(dp[j][k], dp[j][i] + dp[i][k]);
            }
        }
    }//floyd

    int s = 0;
    int t = 0;
    cin >> s >> t;

    printf("%.2lf\n", dp[s - 1][t - 1]);

    return 0;
}

/*
// Dijkstra

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stdio.h>

using namespace std;

const int maxN = 100;
double dp[maxN] = {0};
double e[maxN][maxN] = {{0}};
bool flag[maxN] = {false};

struct Dot {
    int x = 0;
    int y = 0;
}p[maxN];

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }    

    int m = 0;
    cin >> m;

    memset(e, 0x3f3f3f3f, sizeof(e));//gigantic
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        int tmp = abs(p[u - 1].x - p[v - 1].x);
        int tmp2 = abs(p[u - 1].y - p[v - 1].y);
        e[u - 1][v - 1] = sqrt(tmp * tmp  + tmp2 * tmp2);
        e[v - 1][u - 1] = e[u - 1][v - 1];
    }

    int s = 0;
    int t = 0;
    cin >> s >> t;

    for (int i = 0; i < n; i++) {
        dp[i] = e[s - 1][i];
    }

    memset(flag, false, sizeof(flag));
    flag[s - 1] = true;
    dp[s - 1] = 0;

    for (int i = 0; i < n - 1; i++) {
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (!flag[j] && dp[i] < dp[j]) {
                dp[i] = dp[j];
                idx = j;
            }
        }

        if (idx != 0) {
            flag[idx] = true;
            for (int j = 0; j < n; j++) {
                dp[j] = min(dp[j], dp[idx] + e[idx][j]);
            }
        }
    }

    printf("%.2lf\n", dp[t - 1]);

    return 0;
}

*/

/*
// Bellman_Ford

#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 100;
struct Dot {
    int x = 0;
    int y = 0;
}p[maxN];
double e[maxN][maxN] = {{0}};
double dp[maxN] = {0};
int pre[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int m = 0;
    cin >> m;

    memset(e, 0x3f3f3f3f3f, sizeof(e));//gigantic
    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        int tmp = abs(p[u - 1].x - p[v - 1].x);
        int tmp2 = abs(p[u - 1].y - p[v - 1].y);
        e[u - 1][v - 1] = sqrt(tmp * tmp  + tmp2 * tmp2);
        e[v - 1][u - 1] = e[u - 1][v - 1];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (dp[i] + e[i][j] < dp[j]) {
                dp[j] = dp[i] + e[i][j];
                pre[j] = i;
            }
        }
    }

    int s = 0;
    int t = 0;
    cin >> s >> t;

    printf("%.2lf\n", dp[t - 1]);

    return 0;
}
*/