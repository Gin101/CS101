#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int d = 0;
const int maxN = 1e5 + 1;
int deep[maxN] = {0};
bool flag[maxN] = {false};
bool q[maxN] = {false};
vector<int> e[maxN];

int tmp = 0;
int num = 0;
void dfs(int u, int f) {
    deep[u] = deep[f] + 1;
    q[u] &= (deep[u] <= d);

    if (flag[u] && deep[u] > num) {
        num = deep[u];
        tmp = u;
    }

    for (int i = 0; i < e[u].size(); i++) {
        if (e[u][i] != f) {
            dfs(e[u][i], u);
        }
    }
}
int main()
{
    int n = 0;
    int m = 0;
    int result = 0;
    cin >> n >> m >> d;

    memset(q, 1, sizeof(q));
    deep[0] = -1;
	
    for (int i = 1; i <= m; i++) {
        int x = 0;
        cin >> x;

        flag[x] = true;
        tmp = x;
    }

    for (int i = 1; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[x].push_back(y);
        e[y].push_back(x);
    }
	
    dfs(tmp, 0);
    dfs(tmp, 0);
    dfs(tmp, 0);

    for (int i = 1; i <= n; i++) {
        result += q[i];
    }

    cout << result << endl;

	return 0;
}