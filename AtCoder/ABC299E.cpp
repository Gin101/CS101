#include <iostream>
#include <vector>
#include <limits.h>
#include <cstring>

using namespace std;

const int maxN = 2000;
vector<int> e[maxN + 1];
int dis[maxN + 1][maxN + 1] = {{0}};
bool black[maxN + 1] = {false};
bool white[maxN + 1] = {false};
int p[maxN] = {0};
int d[maxN] = {0};

void dfs(int node, int u, int pre, int d) {
    if (dis[node][u] != INT_MAX || dis[u][node] != INT_MAX) {
        return;
    }

    dis[u][node] = min(dis[u][node], d);
    dis[node][u] = min(dis[node][u], d);
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != pre) {
            dfs(node, e[u][i], u, d + 1);
        }
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

        e[u].push_back(v);
        e[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dis[i][j] = INT_MAX;
        }
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, i, i, 0);
    }

    int k = 0;
    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> p[i] >> d[i];

        for (int j = 1; j <= n; j++) {
            if (dis[p[i]][j] < d[i]) {
                white[j] = true;
            }
        }
    }

    bool result = true;
    for (int i = 0; i < k; i++) {
        bool flag = true;       
        for (int j = 1; j <= n; j++) {
            if (dis[p[i]][j] == d[i] && !white[j]) {
                black[j] = true;
                flag = false;
                break;
            }
        }

        if (flag) {
            result = false;
        }
    }

    bool result2 = false;
    for (int i = 1; i <= n; i++) {
        if (black[i]) {
            result2 = true;
        }
    }

    if (!result2) {
        for (int i = 1; i <= n; i++) {
            if (!white[i]) {
                black[i] = true;
                result2 = true;
            }
        }
    }
    
    if (result && result2) {
        cout << "Yes" << endl;
        for (int i = 1; i <= n; i++) {
            cout << black[i];
        }
        cout << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}