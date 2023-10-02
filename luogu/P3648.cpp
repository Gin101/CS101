#include <iostream>

using namespace std;

const int maxN = 1e5 + 1;
const int maxK = 201;
const long long INF = 1e18;
long long a[maxN] = {0};
long long g[maxN] = {0};
long long dp[maxN] = {0};
int f[maxK][maxN] = {{0}};
int tmp[maxN] = {0};
double slope(int x, int y) {
    long long x2 = -a[x];
    long long x3 = -a[y];
    long long y2 = g[x] - a[x] * a[x];
    long long y3 = g[y] - a[y] * a[y];
    if (x2 == x3) {
        return -INF;
    } 
    return (y3 - y2) / (double)(x3 - x2);
}

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i - 1];
    }
 
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j <= n; j++) {
            g[j] = dp[j];
        }
        int l = 0;
        int r = 0;
        for (int j = 1; j <= n; j++) {
            while (r - l >= 2 && slope(tmp[l], tmp[l + 1]) <= a[j]) {
                l++;
            }

            dp[j] = 0;
            if (l < r) {
                f[i][j] = tmp[l];
                dp[j] = g[tmp[l]] + a[tmp[l]] * (a[j] - a[tmp[l]]);
            }

            while (r - l >= 2 && slope(tmp[r - 1], tmp[r - 2]) >= slope(j, tmp[r - 1])) {
                r--;
            }
            tmp[r++] = j;
        }
    }

    cout << dp[n] << endl;
    int result = f[k][n];
    while (k) {
        cout << result << ' ';
        result = f[--k][result];
    }
    cout << endl;

    return 0;
}