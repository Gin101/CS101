#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5;
vector<int> e[maxN];
int result[maxN] = {0};
void dfs(int u, int num) {
    if (result[u]) {
        return;
    }

    result[u] = num;
    for (int i = 0; i < e[u].size(); i++) {
        dfs(e[u][i], num);
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

        e[v - 1].push_back(u - 1);
    }

    for (int i = n - 1; i >= 0; i--) {
        dfs(i, i);
    }
   
    for (int i = 0; i < n; i++) {
        cout << result[i] + 1 << ' ';
    }
    cout << endl;

    return 0;
}