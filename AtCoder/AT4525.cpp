#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 101;
const int maxM = 1e5 + 1;
int w[maxN] = {0};
int v[maxN] = {0};
long long dp[maxN][maxM] = {0};

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		cin >> w[i] >> v[i];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			if (j >= w[i]) {
				if (i == 0) {
					dp[i][j] = v[i];
				} else {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);	
				}
			} else {
				if (i == 0) {
					dp[i][j] = 0;
				} else {
					dp[i][j] = dp[i - 1][j];	
				}
			}
		}
	}
	
	long long result = 0;
	for (int i = 0; i <= m; i++) {
		result = max(result, dp[n - 1][i]);
	}
	
	cout << result << endl;
	
	return 0;
}