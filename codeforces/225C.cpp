#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxM = 1001;
const int INF = 0x3f3f3f3f;
int sum[maxM] = {0};
int dp[maxM][2] = {{0}};
int main()
{
    int n = 0;
    int m = 0;
    int x = 0;
    int y = 0;
    cin >> n >> m >> x >> y;

	for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '#') {
                sum[j + 1]++;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        sum[i] += sum[i - 1];
    }

	memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;
    dp[0][1] = 0;

	for (int i = 0; i < m; i++) {
        for (int j = x; j <= y; j++) {
            if (i + j <= m) {
                dp[i + j][0] = min(dp[i + j][0], dp[i][1] + sum[i + j] - sum[i]);
                dp[i + j][1] = min(dp[i + j][1], dp[i][0] + n * j - sum[i + j] + sum[i]);
            }
        }
    }
		
	cout << min(dp[m][0], dp[m][1]) << endl;

    return 0;
}