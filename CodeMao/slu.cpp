#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 10001;
const int maxM = 1001;
int a[maxN] = {0};
int e[maxN][maxM] = {{0}};
int e2[maxN][maxN] = {{0}};
int pre[maxN][maxM] = {{0}};
int dp[maxN] = {0};
int c[maxN][2] = {{0}};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        e2[i][i] = 0;
        int tmp = 0;
        for (int j = i + 1; j <= n; j++) { 
            tmp += a[j] - a[j - 1];
            e2[i][j] = tmp * tmp;
        }
    }

    memset(e, 0x3f3f3f3f, sizeof(e));//giganic
    for (int i = 0; i <= n; i++) {
        e[i][1] = e2[1][i];
        e[i][i] = 0;
        e[i][0] = 0;
        e[0][i] = 0;
        for (int j = i + 1; j <= n; j++) {
            e[i][j] = 0;
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m && j < i; j++) {
            for (int k = j - 1; k < i; k++) {
                int tmp = e[k][j - 1] + e2[k + 1][i];
                if (tmp < e[i][j]) {
                    e[i][j] = tmp;
                    dp[i] = k;
                    pre[i][j] = k;
                    c[i][0] = k + 1;
                    c[i][1] = i;
                }
            }
        }
    }

    cout << e[n][m] << endl;
}