#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0;
int tot = 0;
int root = 0;
int result = 0;
const int maxN = 201;
const int MOD = 10007;
int head[maxN] = {0};
int big[maxN] = {0};
int size[maxN] = {0};
int dp[maxN][maxN] = {0};
int tmp[maxN] = {0};
struct Node {
	int val = 0;
	int _next = 0;
}e[maxN * 2];

void add (int u,int v) {
	e[++tot]._next=head[u];
	e[tot].val = v;
	head[u] = tot;
}
void getroot(int x,int fa) {
	size[x] = 1;
	big[x] = 0;
	for (int i = head[x]; i; i = e[i]._next) {
		if (e[i].val != fa) {
			getroot(e[i].val, x);
			size[x] += size[e[i].val];
			big[x] = max(big[x], size[e[i].val]);
		}
	}
		
	big[x] = max(big[x], n - size[x]);
	if (big[x] <= big[root] || (!root)) {
		root = x;
	}
}
void dfs(int x,int fa) {
	size[x] = dp[x][0] = dp[x][1] = 1;
	for (int i = head[x]; i; i = e[i]._next) {
		if (e[i].val != fa) { 
			dfs(e[i].val, x);
			for (int j = 1; j <= size[x] + size[e[i].val]; j++) {
				tmp[j] = 0;
			}
			for (int j = 1; j <= size[x]; j++) {
				for (int k = 0; k <= size[e[i].val]; k++) {
					tmp[j + k] = (tmp[j + k] + dp[x][j] * dp[e[i].val][k] % MOD) % MOD;
				}
			}
			size[x] += size[e[i].val];
			for (int j = 1; j <= size[x]; j++) {
				dp[x][j] = tmp[j];
			}
		}
    }
}
void solve1(int x) {
	memset(dp, 0, sizeof(dp));
	dfs(x, 0);
	for (int i = 1; i <= n; i++) {
		memset(dp[x], 0, sizeof(dp[x]));
		size[x] = dp[x][0] = dp[x][1] = 1;
		for (int j = head[x]; j ; j = e[j]._next) {
			for (int k = 1; k <= size[x] + size[e[j].val]; k++) {
				tmp[k] = 0;
			}
			for (int k = 1; k <= size[x]; k++) {
				for (int l = 0; l <= size[e[j].val]; l++) {
					if (l * 2 >= i) {
						break;
					}
					tmp[k + l] = (tmp[k + l] + dp[x][k] * dp[e[j].val][l] % MOD) % MOD;
				}
			}
			size[x] += size[e[j].val];
			for (int k = 1; k <= size[x]; k++) {
				dp[x][k] = tmp[k];
			}
		}
		result = (result + dp[x][i]) % MOD;
	}
}
void solve2(int x,int y) {
	memset(dp, 0, sizeof(dp));
	dfs(x, y);
	dfs(y, x);
	for (int i = 1; i <= n; i++) {
		result = (result + dp[x][i] * dp[y][i] % MOD) % MOD;
	}
}
int main()
{
	int t = 0;
	cin >> t;
	
	int cnt = 0;
	for (int i = 0; i < t; i++) {
		cnt++;
		memset(head, 0, sizeof(head));
		tot = result = 0;
		cin >> n;
		
		for (int i = 1; i < n; i++) {
			int x = 0;
			int y = 0;
			cin >> x >> y;
			
			add(x, y);
			add(y, x);
		}
		
		root = 0;
		getroot(1, 0);
		if (big[root] * 2 < n) {
			solve1(root);
		} else {
			int idx = 0;
			for (int i = head[root]; i > 0; i = e[i]._next) {
				idx = e[i].val;
				if (big[root] == size[idx]) {
					break;
				}
			}
			solve2(root, idx);
		}
		
		cout << "Case " << cnt << ": " << result << endl;
	}
	
	return 0;
}