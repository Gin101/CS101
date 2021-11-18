#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 10000;
vector<int> g[maxN];
vector<int> p[maxN];
int cnt = 0;
int num[maxN] {0};
int tmp = 0;
int result[maxN] = {0};
int idx2 = 0;
bool dis[maxN] = {0};
bool flag[maxN] = {0};
bool flag2[maxN] = {0};
void dfs(int u) {
    flag[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int idx = g[u][i];
        if (!flag[idx]) {
            dis[idx] = dis[u] ^ 1;
            flag2[p[u][i]] = true;
            dfs(idx);
        } else if (!flag2[p[u][i]]) {
            flag2[p[u][i]] = true;
            if (dis[u] == dis[idx]) {
                cnt++;
                num[u]++;
                num[idx]--;
                tmp = p[u][i];
            } else {
                num[u]--;
                num[idx]++;
            }
        }
    }
}

void dfs2(int u) {
    flag[u] = true;
    for (int i = 0; i < g[u].size(); i++) {
        int idx = g[u][i];
        if (!flag[idx]) {
            dfs2(idx);    
            if (num[idx] == cnt) {
                result[idx2++] = p[u][i];
            }  
            num[u] += num[idx];
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

        g[u - 1].push_back(v - 1);
        p[u - 1].push_back(i);
        g[v - 1].push_back(u - 1);
        p[v - 1].push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            dfs(i);
        }
    }

    if (!cnt) {
        cout << m << endl;
        for (int i = 1; i <= m; i++) {
            cout << i << ' ';
        }

        cout << endl;
        return 0;
    }

    memset(flag, false, sizeof(flag));
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            dfs2(i);
        }
    }

    if (cnt == 1) {
        result[idx2++] = tmp;
    }
    
    cout << idx2 << endl;
    sort(result, result + idx2);
    for (int i = 0; i < idx2; i++) {
        cout << result[i] + 1 << ' ';
    }

    cout << endl;

    return 0;
}