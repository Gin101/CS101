#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <limits.h>

using namespace std;

int l = 0;
int r = 0;
const int maxN = 1002;
const long long INF = LONG_LONG_MAX;
int dp[2][maxN][maxN] = {{{0}}};
int sum[maxN] = {0};

struct Node {
    double x = 0;
    double y = 0;
    double v = 0;
} egg[maxN];

bool cmp(Node x, Node y) {
    return x.x < y.x;
}

int main()
{
    int n = 0;
    double m = 0;
    cin >> n >> m;

    egg[1] = Node{m, 0.0, 0.0};
    double tmp = 0;
    for (int i = 2; i <= n + 1; i++) {
        cin >> egg[i].x;
    }
    for (int i = 2; i <= n + 1; i++) {
        cin >> egg[i].y;
    }
    for (int i = 2; i <= n + 1; i++) {
        cin >> egg[i].v;
        tmp += egg[i].v;
    }

    sort(egg + 1, egg + n + 2, cmp);
    for (int i = 1; i <= n + 1; i++) {
        sum[i] = sum[i - 1] + egg[i].v;
        if (fabs(egg[i].x - m) <= 1e-15 && fabs(egg[i].y - 0.0) <= 1e-15) {
            l = i;
            r = i;
        }
    }
    
    memset(dp, -INF, sizeof(dp));
    dp[0][l][r] = 0.00;
    dp[1][r][r] = 0.00;
    for (int i = 1; i <= n + 1; i++) {
        for (int j = 1; j + i <= n + 1; j++) {
            dp[0][j][i + j] = egg[j].y + max(dp[0][j + 1][i + j] - (egg[j + 1].x - egg[j].x) * (sum[n + 1] + sum[j] - sum[i + j]), dp[1][j + 1][i + j] - (egg[i + j].x - egg[j].x) * (sum[n + 1] + sum[j] - sum[i + j]));
            dp[1][j][i + j] = egg[i + j].y + max(dp[1][j][i + j - 1] - (egg[i + j].x - egg[i + j - 1].x) * (sum[n + 1] + sum[j - 1] - sum[i + j - 1]), dp[0][j][i + j - 1] - (egg[i + j].x - egg[j].x) * (sum[n + 1] + sum[j - 1] - sum[i + j - 1]));
        }
    }
    
    printf("%.3lf\n", max(dp[1][1][n + 1], dp[0][1][n + 1]) / 1000.0);

    return 0;
}