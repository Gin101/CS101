#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 101;
const int maxM = 10;
int t[maxN] = {0};
int num[1 << maxM] = {0};
int rec[1 << maxM] = {0};
int dp[maxN][1 << maxM][1 << maxM] = {{{0}}};
bool check(int x) {
    if ((x & (x << 1)) || (x & (x << 2))) {
        return false;
    }
    return true;
}

bool check2(int x, int r) {
    if (x & t[r]) {
        return false;
    }
    return true;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char g;
            cin >> g;

            t[i] *= 2;
            if (g == 'H') {
                t[i]++;
            }
        }
    }

    int idx = 0;
    for (int i = 0; i < (1 << m); i++) {
        if (check(i)) {
            num[idx++] = i;
        }
    }

    int result = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < idx; i++) {
        int tmp = num[i];
        while (tmp != 0) {
            rec[i]++;
            tmp &= (tmp - 1);
        }

        if (check2(num[i], 1)) {
            dp[1][i][0] = rec[i];
            result = max(result, dp[1][i][0]);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < idx; j++) {
            if (!check2(num[j], i)) {
                continue;
            }
            for (int k = 0; k < idx; k++) {
                if (num[j] & num[k]) {
                    continue;
                }
                for (int l = 0; l < idx; l++) {
                    if ((num[j] & num[l]) || (dp[i - 1][k][l] == -1)) {
                        continue;
                    }
                    dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][l] + rec[j]);
                }
                if (i == n) {
                    result = max(result, dp[i][j][k]);
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}