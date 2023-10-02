#include <iostream>
#include <vector>

using namespace std;

const int maxN = 501;
int dis[maxN] = {false};
vector<pair<int, int> > e[maxN];
int l = 0;
int r = 0;
void dfs(int u, int num) {
	dis[u] = num;
	for (int i = 0; i < e[u].size(); i++) {
        if (l <= e[u][i].second && e[u][i].second <= r) {
            continue;
        }

        if (dis[e[u][i].first] != num) {
            dfs(e[u][i].first, num);
        }
	}
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u].push_back({v, i});
        e[v].push_back({u, i});
    }

    int k = 0;
    cin >> k;

    for (int i = 1; i<= k; i++) {
        int result = 0;
        cin >> l >> r;

        for (int j = 1; j <= n; j++) {
            if (dis[j] != i) {
                dfs(j, i);
                result++;
            }
        }

        cout << result << endl;
    }

	return 0;
}