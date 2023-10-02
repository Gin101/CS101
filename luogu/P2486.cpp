#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

const int maxN = 2e4 + 1;
const int maxM = 4e4 + 1;
int dp[maxM] = {0};
int cnt[maxN] = {0};
int num[maxN] = {0};
int tmp[maxN] = {0};

int find(int u) {
    if (cnt[u] == u) {
		return u;
	}

    return cnt[u] = find(cnt[u]);
}

int main()
{
	int n = 0;
	int m = 0;
	int k = 0;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		cnt[i] = i;
		num[i] = 1;
	}

	for (int i = 1; i <= k; i++) {
		int u = 0;
		int v = 0;
		cin >> u >> v;

		if (find(u) != find(v)) {
			num[cnt[v]] += num[cnt[u]];
			cnt[cnt[u]] = cnt[v];
		}
	}

    int idx = 0;
    for (int i = 1; i <= n; i++) {
        if (find(i) == i) {
            tmp[++idx] = num[i];
        }
    }

    sort(tmp + 1, tmp + 1 + idx, greater<int> ());

	for (int i = 1; i <= idx; i++) {
		for (int j = 2 * m; j >= 1; j--) {
			if (j >= tmp[i]) {
				dp[j] = max(dp[j], dp[j - tmp[i]] + tmp[i]);
			} else {
				dp[j] = dp[j - 1];
			}
		}
	}

    cout << dp[m] << endl;

    return 0;
}