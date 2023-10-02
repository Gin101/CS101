#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n = 0;
const int maxN = 4e5 + 1;
vector<int> e[maxN];
int dfn[maxN] = {0};
int idx[maxN] = {0};
int sz[maxN] = {0};
long long result = 0;
int cnt = 0;
void dfs(int u, int f) {
    dfn[u] = ++cnt;
    idx[cnt] = u;
    sz[u] = 1;

    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != f) {
            dfs(e[u][i], u);
            sz[u] += sz[e[u][i]];
            result += 2ll * min(sz[e[u][i]], n - sz[e[u][i]]);
        }
    }
}

int main()
{
    cin >> n;

    for (int i = 1; i < n; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(1, 0);
    cout << result << endl;

    for (int i = 1; i <= n; i++) {
        cout << idx[(dfn[i] + n / 2 - 1) % n + 1] << ' ';
    }

    cout << endl;

    return 0;
}