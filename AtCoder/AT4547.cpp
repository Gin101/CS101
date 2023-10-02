#include <iostream>

using namespace std;

const int maxN = 2e5 + 1;
int idx[maxN] = {0};
long long dp[maxN] = {0};
long long h[maxN] = {0};
double ope(int x, int y) {
	return (dp[x] + h[x] * h[x] - dp[y] - h[y] * h[y]) * 1.0 / (h[x] - h[y]);
}
int main()
{
    int n = 0;
    long long c = 0;
    cin >> n >> c;

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }

	idx[0] = 1;
    int l = 0;
    int r = 0;
	for (int i = 2; i <= n; i++) {
		while (l < r && ope(idx[l + 1], idx[l]) < 2 * h[i]) {
            l++;
        }
		dp[i] = dp[idx[l]] + h[idx[l]] * h[idx[l]] - 2 * h[i] * h[idx[l]] + h[i] * h[i] + c;
		while (l < r && ope(i, idx[r]) < ope(idx[r], idx[r-1])) {
            r--;
        }
		idx[++r] = i;
	}

    cout << dp[n] << endl;

	return 0;
}