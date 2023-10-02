#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 2e6 + 1;
const int INF = 0x3f3f3f3f;
int dp[maxN] = {0};
int dis[maxN] = {0};
int deep[maxN] = {0};
set<int> se[maxN];
vector<pair<int, int> > e[maxN];
vector<int> e2[maxN];
queue<int> q;
int find(int u) {
    return dp[u] == u ? u : dp[u] = find(dp[u]);
}
void check(int u, int v) {
    dp[find(u)] = find(v);
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int x = 0;
        int y = 0;
        int z = 0;
        cin >> x >> y >> z;

        e[z].emplace_back(x, y);
        se[z].insert(x);
        se[z].insert(y);
    }

    for (int i = 1; i <= n; i++) {
        dp[i] = i;
    }

    int num = n;
    for (int i = 1; i <= 1e6; i++) {
        if (!se[i].empty()) {
            for (int j = 0; j < e[i].size(); j++) {
                check(e[i][j].first, e[i][j].second);
            }
            for (auto idx : se[i]) {
                if (dis[find(idx)] == 0) {
                    dis[find(idx)] = ++num;
                }
                e2[idx].push_back(dis[find(idx)]);
                e2[dis[find(idx)]].push_back(idx);
            }
            for (auto idx : se[i]) {
                dis[idx] = 0;
                dp[idx] = idx;
            }
        }
    }

    memset(deep, INF, sizeof(deep));
    deep[1] = 0;
    q.push(1);
    while (!q.empty()) {
        for (int i = 0; i < e2[q.front()].size(); i++) {
            if (deep[e2[q.front()][i]] > 1e8) {
                deep[e2[q.front()][i]] = deep[q.front()] + 1;
                q.push(e2[q.front()][i]);
            }
        }
        q.pop();
    }

    if (deep[n] > 1e8) {
        cout << -1 << endl;
    } else {
        cout << deep[n] / 2 << endl;
    }

    return 0;
}