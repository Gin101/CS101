#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 1e5 + 1;
const int maxP = 32;
int dp[maxN] = {0};
int p[maxN][maxP] = {{0}};
int h[maxN] = {0};
vector<pair<int, int> > e;
vector<int> g[maxN];

void dfs(int v, int pre) {
    for (int u : g[v]) {
        if (u != pre) {
            h[u] = h[v] + 1;
            p[u][0] = v;
            for (int i = 1; i < maxP; i++) {
                p[u][i] = p[p[u][i - 1]][i - 1];
            }

            dfs(u, v);
        } 
    }
}

int parent(int x, int idx) {
    for (int i = 0; i < maxP; i++) {
        if (idx & (1 << i)) {
            x = p[x][i];
        }
    } 
    return x;
}

int lca(int x, int y) {
    if (h[x] < h[y]) {
        swap(x, y);
    } 
    x = parent(x, h[x] - h[y]);
    for (int i  = maxP - 1; i >= 0; i--) {
        if (p[x][i] != p[y][i]) {
            x = p[x][i];
            y = p[y][i];
        }
    }

    return x == y ? x : p[x][0];
}

int dfs2(int v, int idx) {
    for (int u : g[v]) {
        if (u != idx) {
            dp[v] += dfs2(u, v);
        }
    } 
    return dp[v];
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        g[x].push_back(y);
        g[y].push_back(x);

        e.push_back(make_pair(x, y));
    }

    dfs(1, -1);

    int k = 0;
    cin >> k;

    for (int i = 0; i < k; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        dp[x]++;
        dp[y]++;
        dp[lca(x, y)] -= 2;
    }

    dfs2(1, -1);
    for (int i = 0; i < e.size(); i++) {
        if (h[e[i].first] > h[e[i].second]) {
            cout << dp[e[i].first] << ' ';
        } else  {
            cout << dp[e[i].second] << ' ';
        } 
    } 

    cout << endl;

    return 0;
}