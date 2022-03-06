#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 301;
int num[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int dp2[maxN] = {0};

int main() 
{
	int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
	
	for (int i = 1; i <= n; i++) {
		dp[i][i] = 1;
	}
	
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i + 1; j++) {
			int idx = i + j - 1;
			dp[j][idx] = dp[j][idx - 1] + 1;
			for (int k = j; k < idx; k++) {
				if (num[idx] == num[k]) {
					dp[j][idx] = min(dp[j][idx], dp[j][k] + dp[k + 1][idx - 1]);
				}
			}
		}
	}
	
	memset(dp2, 0x3f, sizeof dp2);
	dp2[0] = 0;
	
	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) {
			dp2[i] = dp2[i - 1];
		} else {
			for (int j = 0; j < i; j++) {
				dp2[i] = min(dp2[i], dp2[j] + dp[j + 1][i]);
			}
		}
	}
	
	cout << dp2[n] << endl;
	
	return 0;
}