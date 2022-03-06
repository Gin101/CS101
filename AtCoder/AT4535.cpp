#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 401;
const long long INF = 0x3f3f3f3f3f3f;
int n = 0;
long long a[maxN] = {0};
long long dp[maxN][maxN] = {{0}};

int main()
{
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1, idx; (idx = i + j - 1) <= n; j++) {
            dp[j][idx] = INF;
            for (int k = j; k < idx; k++) {
			    dp[j][idx] = min(dp[j][idx], dp[j][k] + dp[k + 1][idx]);
            }

            for (int k = j; k <= idx; k++) {
                dp[j][idx] += a[k];
            }
		}
    }

	cout << dp[1][n] << endl;
	
	return 0;
}