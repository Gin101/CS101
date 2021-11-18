#include <iostream>

using namespace std;

const int maxN = 21;
const int MOD = 1e9 + 7;
bool graph[maxN][maxN] = {{false}};
int dp[1 << maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    dp[0] = 1;
    for (int i = 1; i < (1 << n); i++) {
        int tmp = i;
        int idx = 0;

        while (tmp != 0) {
            if (tmp % 2 == 1) {
                idx++;
            }
            tmp /= 2;
        }

        for (int j = 0; j < n; j++) {
            if (graph[idx - 1][j] && (i & (1 << j))) {
                dp[i] = (dp[i] % MOD + dp[i - (1 << j)] % MOD) % MOD;
            }
        }
    }

    cout << dp[(1 << n) - 1] % MOD << endl;

    return 0;
}