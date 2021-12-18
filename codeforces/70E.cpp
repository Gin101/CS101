#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 181;
const int INF = 0x3f3f3f3f;
int n = 0;
int k = 0;
int d[maxN] = {0};
vector<int> e[maxN];
int g[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int pre[maxN] = {0};
int result[maxN] = {0};
int dis[maxN][maxN] = {{0}};

void dfs(int u) {
    for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != pre[u]) {
            pre[e[u][i]] = u;
		    dfs(e[u][i]);
        }
	}

	memset(dp[u], INF, sizeof(dp[u]));
	g[u] = 0;
	for (int i = 1; i <= n; i++) {
        dp[u][i] = d[dis[u][i]] + k;
    }
	
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != pre[u]) {
            for (int j = 1; j <= n; j++) {
                dp[u][j] += min(dp[e[u][i]][j] - k, dp[e[u][i]][g[e[u][i]]]);
            }
        }
	}
	
	for (int i = 1; i <= n; i++) {
		if (dp[u][i] < dp[u][g[u]]) {
            g[u] = i;
        }
	}
}

void dfs2(int u) {
	if (dp[u][result[pre[u]]] - k < dp[u][g[u]]) {
        result[u] = result[pre[u]];
    } else {
        result[u] = g[u];
    }

	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != pre[u]) {
            dfs2(e[u][i]);
        }
	}

}

int main()
{
    cin >> n >> k;

    for (int i = 1; i < n; i++) {
        cin >> d[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j) {
                dis[i][j] = INF;
            }
        }
    }

	for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
        dis[u][v] = 1;
        dis[v][u] = 1;
	}

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
				dis[j][k] = min(dis[j][k], dis[j][i] + dis[i][k]);
            }
        }
    } //floyd

    dfs(1);

	cout << dp[1][g[1]] << endl;
	
	result[1] = g[1];
	for (int i = 0; i < e[1].size(); i++) {
		dfs2(e[1][i]);
	} 

	for (int i = 1; i <= n; i++) {
        cout << result[i] << ' ';
    }

    cout << endl;
	
	return 0;
}