#include <iostream>
#include <cstring>

using namespace std;

int m = 0;
const int maxN = 81;
int num[maxN] = {0};

__int128 pre[maxN] = {0};
__int128 dp[maxN][maxN] = {0};
__int128 dfs(int l, int r) {
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    if (r - l >= 1) {
        dp[l][r] = max(num[l] * pre[m - r + l] + dfs(l + 1, r), dfs(l, r - 1) + num[r] * pre[m - r + l]);
    } else {
        dp[l][r] = num[l] * pre[m - r + l];
    }   
    return dp[l][r];
}

void print(__int128 num) {
    if (!num) {
        return;
    }
    if (num) {
        print(num / 10);
    }
    putchar(num % 10 + '0');
}

int main()
{
    int n = 0;
    cin >> n >> m;

    pre[0] = 1;
    for (int i = 1; i <= m; i++) {
        pre[i] = pre[i - 1] * 2;
    }

    __int128 result = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> num[j];
        }
        memset(dp, -1, sizeof(dp));
        result += dfs(1, m);
    }
    
    if (result == 0) {
        cout << 0 << endl;
    } else {
        print(result);
    }

    return 0;
}