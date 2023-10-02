#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include <algorithm>
#include <ranges>

using namespace std;

const int maxN = 1 << 20;
int idx = 0;
int h[maxN] = {0};
int f[maxN] = {0};
int flag[maxN] = {0};
basic_string<int> g[maxN];
int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}
void dfs(int u) {
    flag[u] = true;
    for (idx++; int v : g[u]) {
        if (!flag[v] && h[u] >= h[v]) {
            dfs(v);
        }
    }
}
int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
        f[i] = i;
    }

    vector<tuple<int, int, int, int> >e(m);

    for (auto &[H, w, u, v] : e) {
        cin >> u >> v >> w;
        g[u] += v;
        g[v] += u;
        H = -min(h[u], h[v]);
    }

    dfs(1);
    ranges :: sort(e);

    long long result = 0;
    for (auto[H, w, u, v] : e) {
        if (flag[u] && flag[v]) {
            if (find(u) ^ find(v)) {
                result += w;
                f[find(u)] = find(v);
            }
        }
    }
    cout << idx << ' ' << result << endl;

    return 0; 
}