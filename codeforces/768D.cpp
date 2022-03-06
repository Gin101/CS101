#include <iostream>

using namespace std;

const int maxN = 1001;
const int maxLen = 10001;
double dp[maxLen][maxN] = {{0}};
int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

	dp[0][0] = 1;
	for (int i = 1; i <= maxLen; i++) {
		for(int j = 1; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] * (double)j / n + dp[i - 1][j - 1] * (double)(n - j + 1) / n;
		}
	}

    for (int i = 0; i < q; i++) {
        int p = 0;
        cin >> p;

		for (int j = 1; j <= maxLen; j++) {
			if (dp[j][n] * 2000 > (double)p) {
				cout << j << endl;
				break;
			}
		}
	}
    
	return 0;
}