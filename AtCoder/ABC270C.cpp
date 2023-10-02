#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2e5;
vector<int> e[maxN];
int fa[maxN] = {0};
void dfs(int u, int pre) {
    fa[u] = pre;
    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != pre) {
            dfs(e[u][i], u);
        }
    }
}

int main()
{
    int n = 0;
    int x = 0;
    int y = 0;
    cin >> n >> x > >y;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u].push_back(v);
        e[v].push_back(u);
    }
    
    dfs(y, 0);
    while (x != y) {
        cout << x << endl;
        x = fa[x];
    }

    return 0;
}