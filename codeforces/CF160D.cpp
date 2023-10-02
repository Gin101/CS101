#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
int n = 0;
int m = 0;
int f[maxN] = {0};
int result[maxN] = {0};
int _next[maxN] = {0};
int low[maxN] = {0};
struct Node {
    int u = 0;
    int v = 0;
    int w = 0;
} node[maxN];

vector<int> num;
vector<Node>e[maxN];
vector<array<int, 3> > g[maxN];

int find(int x) {                                       
    if (f[x] == x) {
        return f[x];
    }
    return f[x] = find(f[x]);
}
int merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    return fx != fy ? (f[fx] = fy, 1) : 0;
}

int idx = 0;
void tarjan(int x, int pre) {
    _next[x] = ++idx;
    low[x] = idx;
    for (auto i : g[x]) {
        if (!_next[i[0]]) {
            tarjan(i[0], i[2]);
            low[x] = min(low[x], low[i[0]]);
            result[i[1]] += _next[x] < low[i[0]];
        } else if (pre != i[2]) {
            low[x] = min(low[x], _next[i[0]]);
        }
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> node[i].u >> node[i].v >> node[i].w;
        num.push_back(node[i].w);
    }

    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    for (int i = 1; i <= m; i++) {
        e[lower_bound(num.begin(), num.end(), node[i].w) - num.begin() + 1].push_back({node[i].u, node[i].v, i});
    }
	
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }  
    for (int i = 1; i <= m; i++) {
        for (Node j : e[i]) {
            int fx = find(j.u);
            int fy = find(j.v);
            if (fx != fy) {
                result[j.w]++;
                g[fx].push_back({fy, j.w, ++idx});
                g[fy].push_back({fx, j.w, idx});
            }
        }
        for (Node j : e[i]) {
            merge(j.u, j.v);
        }
    }
	
    for (int i = 1; i <= n; i++) {
        if (!_next[i]) {
            tarjan(i, 0);
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << (result[i] > 1 ? "any" : result[i] ? "at least one" : "none") << endl;
    }
	
    return 0;
}
