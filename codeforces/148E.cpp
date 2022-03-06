#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 101;
int dp[maxN][maxN] = {{0}};
int dp2[maxN][maxN * maxN] = {{0}};
int sum[maxN][maxN] = {{0}};
vector<int> e[maxN];
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int k = 0;
        cin >> k;

		for (int j = 1; j <= k;j++) {
            int v = 0;
            cin >> v;

			e[i].push_back(v);
			sum[i][j] = sum[i][j - 1] + v;
		}
	}

    for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= e[i].size(); j++) {
			for (int k = 0; k <= j; k++) {
				dp[i][j] = max(dp[i][j], sum[i][e[i].size()] - sum[i][e[i].size() - j + k] + sum[i][k]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= e[i].size() && k <= j; k++) {
				dp2[i][j] = max(dp2[i][j], dp2[i - 1][j - k] + dp[i][k]);
			}
		}
	} 

	cout << dp2[n][m] << endl;

	return 0;
}