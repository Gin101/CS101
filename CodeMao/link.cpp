#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
vector<int> e[maxN];
int w[maxN] = {0};
bool flag[maxN] = {false};

int result2 = 0;
int result = 0;
int tmp = 0;
void dfs(int now, int cnt) {
    if (cnt == 2) {
        result += (w[tmp] * w[now]);
        result2 = max(result2, w[tmp] * w[now]);
        return;
    }

    for (int i = 0; i < e[now].size(); i++) {
        if (!flag[e[now][i]]) {
            dfs(e[now][i], cnt + 1);
        }
    }
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < n; i++) {
        tmp = i;
        flag[i] = true;
        dfs(i, 0);
    }

    cout << result2 << ' ' << 2 * result << endl;

    return 0;
}