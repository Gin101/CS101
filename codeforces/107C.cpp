#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 16;
int q[maxN] = {0};
int result[maxN] = {0};
long long dp[1 << maxN] = {0};

int main()
{
    int n = 0;
    long long y = 0;
    int m = 0;
    cin >> n >> y >> m;

    y -= 2000;

    for (int i = 1; i <= m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        q[b - 1] |= 1 << a - 1;
    }

    memset(result, -1, sizeof(result));
    for (int i = 0; i < n; i++) {
        result[i] = 0;
        while (result[i] < n) {
            memset(dp, 0, sizeof(dp));
            dp[0] = 1;
            for (int j = 0; j < (1 << n); j++) {
                int tmp = __builtin_popcount(j);
                for (int k = 0; k < n; k++) {
                    if (!(j & (1 << k)) && (result[k] == tmp || result[k] == -1) && (j & q[k]) == q[k]) {
                        dp[j | (1 << k)] += dp[j];
                    }
                }
            }
            if (dp[(1 << n) - 1] >= y) {
                break;
            }
            y -= dp[(1 << n) - 1];
            result[i]++;
        }
        if (result[i] >= n) {
            cout << "The times have changed" << endl;
            return 0;
        }
    }

	for (int i = 0; i < n; i++) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;

	return 0;
}