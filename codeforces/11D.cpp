#include <iostream>

using namespace std;

const int maxN = 19;
bool a[maxN][maxN] = {{0}};
long long dp[1 << maxN][maxN] = {{0}};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        a[u - 1][v - 1] = true;
        a[v - 1][u - 1] = true;
    }

    for (int i = 0; i < n; i++) {
        dp[1 << i][i] = 1;
    }

    long long result = 0;
    for (int i = 1; i <= (1 << n); i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (!a[j][k] || (i & -i) > 1 << k) {
                    continue;
                }
                if ((1 << k) & i) {
                    if ((1 << k) == (i & -i)) {
                        result += dp[i][j];
                    }
                } else {
                    dp[i | (1 << k)][k] += dp[i][j];
                }
            }
        }
    }

    cout << (result - m) / 2 << endl;

    return 0;
}