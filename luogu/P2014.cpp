#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 301;
int num[maxN] = {0};
int dp[maxN][maxN] = {0};
struct Node {
    int val = 0;
    int next = 0;
} e[maxN];

int dfs(int u) {
    int sum = 0;
    int tmp = num[u];
    while (tmp) {
        sum += dfs(e[tmp].val) + 1;
        for (int i = sum; i >= 1; i--) {
            for (int j = 0; j <= i; j++) {
                if (i - j - 1 >= 0) {
                    dp[u][i] = max(dp[u][i], dp[e[tmp].val][j] + dp[u][i - j - 1]);
                }
            }
        }
        tmp = e[tmp].next;
    }

    return sum;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        int k = 0;
        int score = 0;
        cin >> k >> score;

        e[++idx].val = i;
        e[idx].next = num[k];
        num[k] = idx;

        dp[i][0] = score;
    }

    dfs(0);
    cout << dp[0][m] << endl;

    return 0;
}