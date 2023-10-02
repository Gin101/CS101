#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

int t = 0;
const int maxN = 1e4;
bool vis[maxN] = {false};
vector<int> e[maxN];
bool flag = false;
int dfs(int u, int cnt, int pre) {
    vis[u] = true;

    if (u == t - 1) {
        return cnt;
    }

    int result = INT_MAX; 
    for (int i = 0; i < e[u].size(); i++) {
        if (!vis[e[u][i]]) {
            result = min(result, dfs(e[u][i], cnt + 1, u));
            vis[e[u][i]] = true;
        }
    }

    return result;
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[x - 1].push_back(y - 1);
    }

    int s = 0;
    cin >> s >> t;

    cout << dfs(s - 1, 0, 0) << endl;

    return 0;
}