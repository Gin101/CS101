#include <iostream>
#include <vector>

using namespace std;

int n = 0;
const int maxN = 5001;
int cnt = 0;
int idx = 0;
int result = 0;
int sc = 0;
int total = 0;
vector<int> e[maxN];
int dfn[maxN] = {0};
int low[maxN] = {0};
bool flag[maxN] = {false};
int st[maxN] = {0};
int scc[maxN] = {0};
int sz[maxN] = {0};
void tarjan(int u) {
    dfn[u] = low[u] = ++cnt;
    flag[u] = true;
    st[++idx] = u;

    for (int i = 0; i < e[u].size(); i++) {
        if (!dfn[e[u][i]]) {
            tarjan(e[u][i]);
            low[u] = min(low[u], low[e[u][i]]);
        } else if (flag[e[u][i]]) {
            low[u] = min(low[u], dfn[e[u][i]]);
        }
    }

    if (dfn[u] == low[u]) {
        sc++;
        int v = 0;
        do {
            v = st[idx--];
            flag[v] = false;
            scc[v] = sc;
        } while (u != v);
    }
}
int main()
{
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        int a = 0;
        int b = 0;
        int t = 0;
        cin >> a >> b >> t;

        e[a].push_back(b);
        if (t == 2) {
            e[b].push_back(a);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++) {
        sz[scc[i]]++;
    }

    for (int i = 1; i <= sc; i++) {
        if (sz[i] > result) {
            result = sz[i];
            total = i;
        }
    }

    cout << result << endl;
    for (int i = 1; i <= n; i++) {
        if (scc[i] == total) {
            cout << i << ' ';
        }
    }
    cout << endl;

	return 0;
}