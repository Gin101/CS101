#include <iostream>
#include <stdio.h>

using namespace std;

int n = 0;
const int maxN = 301;
int cnt = 0;
int cnt2 = 0;
int cnt3 = 0;
double dp[maxN][maxN][maxN] = {{{0}}};
double dfs(int idx,int idx2,int idx3) {
	if (idx == 0 && idx2 == 0 && idx3 == 0) {
		return 0;
	}
	if (dp[idx][idx2][idx3] > 0) {
		return dp[idx][idx2][idx3];
	}
	if (idx) {
		dp[idx][idx2][idx3] += 1.0 * idx / n * dfs(idx - 1, idx2, idx3);
	}
	if (idx2)  {
		dp[idx][idx2][idx3] += 1.0 * idx2 / n * dfs(idx + 1, idx2 - 1, idx3);
	}
	if (idx3) {
		dp[idx][idx2][idx3] += 1.0 * idx3 / n * dfs(idx, idx2 + 1, idx3 - 1);
	}
	
	dp[idx][idx2][idx3]++;
	dp[idx][idx2][idx3] *= 1.0 * n / (idx + idx2 + idx3);
	return dp[idx][idx2][idx3];
}
int main()
{
    cin >> n;
	dp[0][0][0] = 0;
	for (int i = 1; i <= n; i++) {
        int x = 0;
        cin >> x;

		if (x == 1) {
            cnt++;
        }
		if (x == 2) {
            cnt2++;
        }
		if (x == 3) {
			cnt3++;
		}
	}

	printf("%0.9lf\n", dfs(cnt, cnt2, cnt3));

	return 0;
}