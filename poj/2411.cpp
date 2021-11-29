#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxHW = 11;
bool flag[1 << maxHW] = {false};
long long dp[1 << maxHW][1 << maxHW] = {{0}};
int w = 0;
bool check(int x) {
    int cnt = 0;
    while(x) {
        if (x & 1) {
            cnt++;
        } else {
            if (cnt & 1) {
                return false;
            }
            cnt = 0;
        }

        x /= 2;
    }
    return (cnt & 1) == 0;
}

bool check2(int x, int y) {
    if ((x | y) != (1 << w) - 1) {
        return false;
    }
    return flag[x & y];
}

int main()
{
    int h = 0;

    for(int i = 0; i < (1 << 11); i++) {
        flag[i] = check(i);
    }

    while (cin >> h >> w && !(h == 0 && w == 0)) {
        memset(dp, 0, sizeof(dp));

        if (h < w) {
            swap(h, w);
        }

        for (int i = 0; i < (1 << w); i++) {
            dp[1][i] = flag[i];
        }

        for (int i = 2; i <= h; i++) {
            for (int j = 0; j < (1 << w); j++) {
                for (int k = 0; k < (1 << w); k++) {
                    if (check2(j, k)) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }

        cout << dp[h][(1 << w) - 1] << endl;
    }

    return 0;
}
/*
如果是横着的就定义(1,1),如果竖着的定义为竖着的(0,1),状态兼容时只需考虑两种情况,当前行 | 上一行,是不是全为1,不是说明竖着有空（不能出现竖着的(0, 0)）,然后再当前行 & 上一行,这里被消掉的1全部用来竖着放的，判断之后的状态是否有奇数的连续1，有则不能转移的，因为剩下的都是用来行着放了。
*/