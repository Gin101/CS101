#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;

int m = 0;
const int maxN = 8;
const int maxM = 71;
const int INF = 0x3f3f3f3f;
int dp[2][1 << maxN][1 << maxN] = {{{0}}};
int s[maxM] = {0};

bool check(int step, int x, int y) {
    if (step >= 1 && !(x & (1 << (step - 1))) && !(y & (1 << (step - 1)))) {
        return false;
    }
    if (step >= 2 && !(x & (1 << (step - 1))) && !(x & (1 << (step - 2)))) {
        return false;
    }
    return true;
}
void dfs(int sum, int i, int x, int y, int st, int step) {
    if (!check(step, x, y)) {
        return;
    }
    if (step == m) {
        dp[i][st][x] = min(dp[i][st][x], sum);
        return;
    }
    
    if (!(x & (1 << step)) && !(st & (1 << step))) {
        dfs(sum + 1, i, x | (1 << step), y, st | (1 << step), step + 1);
    }
    if (step + 2 <= m && !(x & (1 << step)) && !(x & (1 << (step + 1)))) {
        dfs(sum + 1, i, x | (1 << step) | (1 << (step + 1)), y, st, step + 2);
    }
    dfs(sum, i, x, y, st, step + 1);
}
int main()
{
    int n = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            s[i] |= (str[j] == '*' ? 1 : 0) << j;
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[1][s[1]][(1 << m) - 1] = 0;
    for (int i = 2; i <= n + 1; i++) {
        memset(dp[i & 1], INF, sizeof(dp[i & 1]));
        for (int j = 0; j < (1 << m); j++) {
            for (int k = 0; k < (1 << m); k++) {
                if (dp[(i + 1) & 1][j][k] != INF) {
                    dfs(dp[(i + 1) & 1][j][k], i & 1, j, k, s[i], 0);
                }
            }
        }
    }
    
    int result = INF;
    for (int i = 0; i < (1 << m); i++) {
        result = min(result, dp[(n + 1) & 1][0][i]);
    }
    
    cout << result << endl;

    return 0;
}