#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

const int maxN = 4e5 + 1;
int fa[maxN] = {0};
int bro[maxN] = {0};
int vis[maxN] = {0};
int result[maxN] = {0};
vector<int> e[maxN];
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    iota(fa + 1, fa + 1 + n, 1);

    for (int i = 1; i <= m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u + 1].push_back(v + 1);
        e[v + 1].push_back(u + 1);
    }

    int k = 0;
    cin >> k;

    for (int i = 1; i <= k; i++) {
        cin >> bro[i];
        vis[++bro[i]] = true;
    }

    int cnt = n - k;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            for (auto v : e[i]) {
                if (!vis[v] && find(i) != find(v)) {
                    fa[find(i)] = find(v);
                    cnt--;
                }
            }
        }
    }

    for (int i = k; i > 0; i--) {
        result[i] = cnt;
        vis[bro[i]] = false;
        cnt++;

        for (int v : e[bro[i]]) {
            if (!vis[v] && find(bro[i]) != find(v)) {
                fa[find(bro[i])] = find(v);
                cnt--;
            }
        }
    }
    
    result[0] = cnt;
    for (int i = 0; i <= k; i++) {
        cout << result[i] << endl;
    }

    return 0;
}