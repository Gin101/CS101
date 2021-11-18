#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e4;
vector<int> e[maxN];
bool flag[maxN] = {false};
bool result[maxN] = {false};
int low[maxN] = {0};
int depth[maxN] = {0};
int root = 0;
void dfs(int u, int v) {
    flag[u] = true;
    if (u == v) {
        depth[u] = 0;
    } else {
        depth[u] = depth[v] + 1;
    }

    low[u] = depth[u];

    int num = 0;
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] == v) {
            continue;
        }

        if (flag[e[u][i]]) {
            low[u] = min(low[u], depth[e[u][i]]);
        } else {
            num++;
            dfs(e[u][i], u);
            low[u] = min(low[u], low[e[u][i]]);

            if (low[e[u][i]] >= depth[u]) {
                result[u] = true;
            }
        }
    }

    if (u == v && num == 1) {
        result[u] = false;
    }
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;
        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            root = i;
            dfs(i, i);
        }
    }

    int result2 = 0;
    for (int i = 0; i < n; i++) {
        if (result[i]) {
            result2++;
        }
    }

    cout << result2 << endl;
    for (int i = 0; i < n; i++) {
        if (result[i]) {
            cout << i + 1 << ' ';
        }
    }
    cout << endl;

    return 0;
}