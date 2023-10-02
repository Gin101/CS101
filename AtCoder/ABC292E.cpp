#include <iostream>
#include <vector>

using namespace std;

const int maxN = 2000;
int num[maxN] = {0};
vector<int> e[maxN];
int result = 0;
void dfs(int u, int idx) {
    num[u] = idx;
    result++;
    for (int i = 0; i < e[u].size(); i++) {
        if (num[e[u][i]] < idx) {
            num[e[u][i]] = idx;
            dfs(e[u][i], idx);
        }
    }

    return;
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

        e[u - 1].push_back(v - 1);
    }

    for (int i = 0; i < n; i++) {
        dfs(i, i + 1);
    }

    cout << result - n - m << endl;

	return 0;
}