#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 1001;
const int maxM = 1e5 + 1;
const int INF = 0x3f3f3f3f;
int w[maxN] = {0};
int v[maxN] = {0};
int dp[maxM] = {0};

int main()
{
	int n = 0;
	int m = 0;
	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> w[i] >> v[i];
	}
	
	memset(dp, INF, sizeof(dp));
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1000 * n; j >= v[i]; j--) {
			dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	
	for (int i = 1000 * n; i != 0; i--) {
		if (dp[i] <= m) {
			cout << i << endl;
			return 0;
		}
	}
	
	return 0;
}