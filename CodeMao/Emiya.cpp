#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

const int maxN = 100;
const int maxM = 2000;
int a[maxN][maxM] = {{0}};
int kind[maxM] = {0};
long long result = 0;
int n = 0;
float m = 0;
bool flag = true;
int maxKind = 0;
int maxIdx = 0;

void dfs(int now, float cnt, long long pre) {
    pre %= 998244353;
    if (flag) {
        for (int i = 0; i < m; i++) {
            if (kind[i] > floor(cnt / 2)) {
                flag = false;
                break;
            }
        }
    }
 
    if (cnt != 0 && flag) {
        result += pre;
        result %= 998244353;
    }
    flag = true;

    if (now == n || maxKind > floor(n / 2)) {
        return;
    }

    for (int i = 0; i < m; i++) {
        if (a[now][i] != 0) {
            kind[i]++;
            pre *= a[now][i];

            if (kind[i] > maxKind) {
                maxKind = kind[i];
                maxIdx = i;
            }

            dfs(now + 1, cnt + 1, pre);//choose

            pre /= a[now][i];
            kind[i]--;

            if (maxIdx == i) {
                maxKind--;
            }
        }
    }

    if (now + 1 != n) {
        flag = false;
        dfs(now + 1, cnt, pre);
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cin >> a[i][j];
            scanf("%d", &a[i][j]);
        }
    }

    dfs(0, 0, 1);

    // cout << result << endl;
    printf("%lld\n", result);

    return 0;
}