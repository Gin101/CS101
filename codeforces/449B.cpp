#include <iostream>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxN = 2e5 + 1;
set<pair<int, int> > se;
int dis[maxN] = {0};
bool flag[maxN] = {false};
vector<pair<int, int> > e[maxN];
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        int u = 0;
        int v = 0;
        int x = 0;
        cin >> u >> v >> x;

        e[u].push_back({x, v});
        e[v].push_back({x, u});
    }

    memset(dis, INF, sizeof(dis));
	se.insert({0, 1});
    dis[1] = 0;

    for (int i = 1; i <= k; i++) {
        int s = 0;
        int y = 0;
        cin >> s >> y;
        if (dis[s] > y) {
            se.erase({dis[s], s});
            dis[s] = y;
            se.insert({y, s});
            flag[s] = true;
        }
    }

	while (!se.empty()) {
		auto [tmp, idx] = (*se.begin()); se.erase(se.begin());
        for (int i = 0; i < e[idx].size(); i++) {
            if (dis[e[idx][i].second] > dis[idx] + e[idx][i].first || (flag[e[idx][i].second] && dis[e[idx][i].second] == dis[idx] + e[idx][i].first)) {
                flag[e[idx][i].second] = false;
                se.erase({dis[e[idx][i].second], e[idx][i].second});
                dis[e[idx][i].second] = dis[idx] + e[idx][i].first;
                se.insert({dis[e[idx][i].second], e[idx][i].second});
            }
        }
	}

    for (int i = 1; i <= n; i++) {
        if (flag[i]) {
            k--;
        }
    }

    cout << k << endl;

    return 0;
}