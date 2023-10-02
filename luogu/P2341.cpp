#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 1e4;
const int maxM = 5e4;
int a[maxM] = {0};
int b[maxM] = {0};
vector<int> e[maxN];
vector<int> ne[maxN];
int dfn[maxN] = {0};
int low[maxN] = {0};
int scc[maxN] = {0};
int sz[maxN] = {0};
int s[maxN] = {0};
bool flag[maxN] = {false};
bool nid[maxN] = {false};
int cnt = 0;
int idx = 0;
int sc = 0;

void targan(int u) {
    low[u] = dfn[u] = cnt++;
    s[idx++] = u;
    flag[u] = true;
    for (int i = 0; i < e[u].size(); i++) {
        if (dfn[e[u][i]] == 0) {
            targan(e[u][i]);
            low[u] = min(low[u], low[e[u][i]]);
        } else if (flag[e[u][i]]) {
            low[u] = min(low[u], low[e[u][i]]);
        }
    }

    if (dfn[u] == low[u]) {
        idx--;
        while (s[idx] != u) {
            scc[s[idx]] = sc;
            sz[sc]++;
            flag[s[idx]] = false;
            idx--;
        }
        scc[s[idx]] = sc;
        sz[sc]++;
        flag[s[idx]] = false;
        sc++;
    }
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    
    for (int i = 0; i < m; i++) {
        cin >> a[i] >> b[i];

        e[a[i] - 1].push_back(b[i] - 1);
    }

    memset(scc, -1, sizeof(scc));
    targan(0);

    if (sc == 1) {
        cout << n << endl;
        return 0;
    }

    for (int i = 0; i < n; i++) {
        cout << scc[i] << ' ' ;
    }
    cout << endl;
    for (int i = 0; i < sc; i++) {
        cout << sz[i] << ' ';
    }
    cout << endl;

    for (int i = 0; i < m; i++) {
        if (scc[a[i] - 1] != scc[b[i] - 1]) {
            cout << scc[a[i] - 1] << ' ' << scc[b[i] - 1] << endl;
            ne[scc[a[i] - 1]].push_back(scc[b[i] - 1]);
            nid[scc[a[i] - 1]] = true;
            nid[scc[b[i] - 1]] = true;
        }
    }

    int tc = 0;
    int ti = 0;
    for (int i = 0; i < n; i++) {
        if (nid[i] && ne[i].empty()) {
            tc++;
            ti = i;
        }
    }

    if (tc == 1) {
        cout << sz[ti] << endl;
    } else {    
        cout << 0 << endl;
    }

    return 0;
}