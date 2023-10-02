#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 2e5 + 1;
const int INF = 0x3f3f3f3f;
int a[maxN] = {0};
int b[maxN] = {0};
int c[maxN] = {0};
long long dp[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    memset(dp, INF, sizeof(dp));
    dp[1] = 0;
    for (int i = 1; i <= k; i++) {
        int e = 0;
        cin >> e;

        dp[b[e]] = min(dp[a[e]] + c[e], dp[b[e]]);
    }
	
    if (dp[n] == dp[0]) {
        cout << -1 << endl;
    } else {
        cout << dp[n] << endl;
    }

	return 0;
}