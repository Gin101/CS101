#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define int long long

const int maxZ = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int dp[maxZ] = {0};

signed main()
{
    int n = 0;
    cin >> n;

    memset(dp, INF, sizeof(dp));

    int result = 0;
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        int z = 0;
        cin >> x >> y >> z;

        result += z;
        for (int j = 1e5; j > 0; j--) {
            dp[j] = min(dp[j], dp[max(0ll, j - z)] + max(0ll, (y - x) / 2 + 1));
        }
    }
	
    cout << dp[result / 2 + 1] << endl;

    return 0;
}