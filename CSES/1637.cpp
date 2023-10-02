#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 1e6 + 1;
const int INF = 0x3f3f3f3f;
int dp[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    memset(dp, INF, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= n; i++) {
        int tmp = i;
        while (tmp) {
            dp[i] = min(dp[i], dp[i - tmp % 10] + 1);
            tmp /= 10;
        }
    }

    cout << dp[n] << endl;

    return 0;
}