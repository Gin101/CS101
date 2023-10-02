#include <iostream>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int dp[maxN] = {0};
signed main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int h = 0;
        cin >> h >> h;

        for (int j = 1; j <= n; j++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);

        int result = 0;
        memset(dp, 0, sizeof(dp));
        for (int j = 1; j <= 3; j++) {
            int dp[5] = {1, 2, 2, 2};
            dp[j] = 3;
            int idx = 0;
            int tmp = h;
            for (int k = 0; k <= 3; k++) {
                tmp *= dp[k];
                while (idx < n && tmp > a[idx + 1]) {
                    tmp += a[idx + 1] / 2;
                    idx++;
                }
                result = max(result, idx);
            }
        }

        cout << result << endl;
    }
	
    return 0;
}