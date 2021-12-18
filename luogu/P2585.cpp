#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int maxN = 5e5;
vector<int> e[maxN];
int g[maxN] = {0};// when i is green, the root is i and max of green / when i is green the root is i and min of green
int o[maxN] = {0};// when i isn't green, the root is i and max of green / when i isn't green the root is i and min of green

string s;
int idx = 0;
void init(int num, int root) {
    for (int i = 0; i < num; i++) {
        e[root].push_back(++idx);
        init(s[idx] - '0', idx);
    }
}

void dfs_max(int u) {
    if (e[u].size() == 0) {
        g[u] = 1;
        o[u] = 0;
    } else if (e[u].size() == 1) {
        dfs_max(e[u][0]);
        g[u] = o[e[u][0]] + 1;
        o[u] = max(g[e[u][0]], o[e[u][0]]);
    } else {
        dfs_max(e[u][0]);
        dfs_max(e[u][1]);

        g[u] = o[e[u][0]] + o[e[u][1]] + 1;
        o[u] = max(g[e[u][0]] + o[e[u][1]], g[e[u][1]] + o[e[u][0]]);
    }
}

void dfs_min(int u) {
    if (e[u].size() == 0) {
        g[u] = 1;
        o[u] = 0;
    } else if (e[u].size() == 1) {
        dfs_min(e[u][0]);
        g[u] = o[e[u][0]] + 1;
        o[u] = min(g[e[u][0]], o[e[u][0]]);
    } else {
        dfs_min(e[u][0]);
        dfs_min(e[u][1]);

        g[u] = o[e[u][0]] + o[e[u][1]] + 1;
        o[u] = min(g[e[u][0]] + o[e[u][1]], g[e[u][1]] + o[e[u][0]]);
    }
}

int main()
{
    cin >> s;

    init(s[0] - '0', 0);

    dfs_max(0);

    cout << max(g[0], o[0]) << ' ';

    dfs_min(0);

    cout << min(g[0], o[0]) << endl;

    return 0;
}