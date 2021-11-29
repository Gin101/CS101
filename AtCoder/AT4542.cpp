#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 16;
int a[maxN][maxN] = {{0}};
long long dp[1 << maxN] = {0};
long long sum[1 << maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

	for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

	for (int i = 1; i <= (1 << n) - 1; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < j; k++) {
                if (((1 << k) & i) && ((1 << j) & i)) {
                    sum[i] += a[j][k];
                }
            }
        }
    }

    for (int i = 1; i <= (1 << n) - 1; i++) {
        dp[i] = sum[i];
        int idx = i & (i - 1);
        while (idx) {
            dp[i] = max(dp[i], dp[i ^ idx] + dp[idx]);
            idx = i & (idx - 1);
        }
    }

	
    cout << dp[(1 << n) - 1] << endl;
    
	return 0;
}