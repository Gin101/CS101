#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 1e6 + 1;
vector<int> e[maxN];
int n = 0;
int dp[maxN][2] = {{0}};
int son[maxN] = {0};
int sz[maxN] = {0}; // the size of the son
int pos[maxN] = {0};
bool result[maxN] = {0};
int g[maxN] = {0};

void dfs(int u, int f) {
	sz[u] = 1;
	for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != f){
			dfs(e[u][i], u);
			sz[u] += sz[e[u][i]];
			if (sz[e[u][i]] > sz[son[u]]) {
                son[u] = e[u][i];
            }

			int tmp = (sz[e[u][i]] <= n / 2 ? sz[e[u][i]] : dp[e[u][i]][0]);
			if (dp[u][0] < tmp) {
                dp[u][1] = dp[u][0];
                dp[u][0] = tmp;
                pos[u] = e[u][i];
            } else if (dp[u][1] < tmp) {
                dp[u][1] = tmp;
            }
		}
    }
}

void dfs2(int u, int f) {
	if (max(sz[son[u]], n - sz[u]) <= n / 2) {
        result[u] = true;
    } else if (sz[son[u]] > n / 2) {
        result[u] = (sz[son[u]] - dp[u][0] <= n / 2);
    } else {
        result[u] = (n - sz[u] - g[u] <= n / 2);
    }

	for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != f) {
			if (n - sz[e[u][i]] <= n / 2) {
                g[e[u][i]] = n - sz[e[u][i]];
            } else {
                g[e[u][i]] = g[u];
            }

			if (pos[u] == e[u][i]) {
                g[e[u][i]] = max(g[e[u][i]], dp[u][1]);
            } else {
                g[e[u][i]] = max(g[e[u][i]], dp[u][0]);
            } 

			dfs2(e[u][i], u);
		}
    }
}

int main()
{
    cin >> n;

	for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
		cin >> u >> v;

		e[u].push_back(v);
        e[v].push_back(u);
	}

	dfs(1, 0);
    dfs2(1, 0);

	for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }

    cout << endl;
	
	return 0;
}