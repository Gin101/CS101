#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e4 + 1;
const int maxK = 100;
int a[maxK] = {0};
int dp[maxN] = {0};
int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < k; j++) {
			if (i >= a[j]) {
				dp[i] = max(dp[i], a[j] + (i - a[j]) - dp[i - a[j]]);
			}
		}
	}
	
	cout << dp[n] << endl;

	return 0;
}
