#include <iostream>

using namespace std;

const int maxN = 1e5 + 1;
const int MOD = 1e9 + 7;
int num[maxN][20] = {0};
int f[maxN * 20] = {0};
int son[maxN * 20][20] = {0};
int find(int x) {
    if (f[x] == x) {
        return f[x];
    } else {
        return f[x] = find(f[x]);
    }
}
long long power(long long x, int y) {
    long long result = 1;
    while (y) {
        if (y & 1) {
            (result *= x) %= MOD;
        }
        (x *= x) %= MOD;
        y /= 2;
    }
    return result;
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    int idx = 0;
    for (int i = 0; (1 << i) - 1 <= n; i++) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            num[j][i] = ++idx;
            f[idx] = idx;
            if (i) {
                son[idx][0] = num[j][i - 1];
                son[idx][1] = num[j + (1 << i - 1)][i - 1];
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        int l1 = 0;
        int r1 = 0;
        int l2 = 0;
        int r2 = 0;
        cin >> l1 >> r1 >> l2 >> r2;

        int tmp = r1 - l1 + 1;
        for (int j = 19; j >= 0; j--) {
            if ((1 << j) <= tmp) {
                int fx = find(num[l1][j]);
                int fy = find(num[l2][j]);
                if (fx != fy) {
                    f[fx] = fy;
                }
                tmp -= (1 << j);
                l1 += (1 << j);
                l2 += (1 << j);
            }
        }
    }

    for (int i = 19; i >= 0; i--) {
        for (int j = 1; j + (1 << i) - 1 <= n; j++) {
            if (find(num[j][i]) != num[j][i]) {
                int fx = find(son[num[j][i]][0]);
                int fy = find(son[f[num[j][i]]][0]);
                if (fx != fy) {
                    f[fx] = fy;
                }
                fx = find(son[num[j][i]][1]);
                fy = find(son[f[num[j][i]]][1]);
                if (fx != fy) {
                    f[fx] = fy;
                }
            }
        }
    }
    
    int result = 0; 
    for (int i = 1; i <= n; i++) {
        if (find(num[i][0]) == num[i][0]) {
            result++;
        }
    }

    cout << 9 * power(10, result - 1) % MOD << endl;

    return 0;
}