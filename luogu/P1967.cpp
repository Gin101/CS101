#include <iostream>
#include <unordered_set>
#include <cstring>

using namespace std;

const int maxN = 1e4 + 1;
const int maxM = 5e4 + 1;
const int maxQ = 3e4 + 1;

int fa[maxN] = {0};
int result[maxQ] = {0};
struct Edge {
    int u = 0;
    int v = 0;
    int w = 0;
} e[maxM];

unordered_set<int> s[maxN];
bool cmp(Edge x, Edge y) {
    return x.w > y.w;
}
int find(int x) {
    return fa[x] == x ? x : fa[x] = find(fa[x]);
}
int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= m; i++) {
        cin >> e[i].v >> e[i].u >> e[i].w;
    }
    int q = 0;
    cin >> q;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }

    for (int i = 0; i < q; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        s[u].insert(i);
        s[v].insert(i);
    }

    sort(e + 1, e + m + 1, cmp);
    memset(result, -1, sizeof(result));

    for (int i = 1; i <= m; i++) {
        int u = find(e[i].u);
        int v = find(e[i].v);
 
        if (u == v) {
            continue;
        }
        if (s[u].size() > s[v].size()) {
            swap(u, v);
        }

        for (int j : s[u]) {
            if (s[v].count(j)) {
                result[j] = e[i].w;
            } else {
                s[v].insert(j);
            }
        }
        fa[u] = v;
    }

    for (int i = 0; i < q; i++) {
        cout << result[i] << endl;
    }

    return 0;
}