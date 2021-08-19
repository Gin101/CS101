#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

const int maxN = 299998;
vector<int> e[maxN];
int w[maxN] = {0};
int tmp[maxN] = {0};
int result[maxN] = {0};
int t = 0;
int idx = 0;
bool flag = true;
void dfs(int s, int pre, int cnt) {
    tmp[cnt] = s;

    if (s == t - 1) {
        idx = cnt;
        flag = false;
        return;
    }

    for (int i = 0; i < e[s].size(); i++) {
        if (!flag) {
            return;
        }

        if (e[s][i] != pre) {
            dfs(e[s][i], s, cnt + 1);
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        // cin >> u >> v;
        scanf("%d %d", &u, &v);

        e[u - 1].push_back(v - 1);
        e[v - 1].push_back(u - 1);
    }

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    for (int i = 0; i < m; i++) {
        int s = 0;
        cin >> s >> t;
        
        flag = true;
        dfs(s - 1, s - 1, 0);
        for (int j = 0; j <= idx; j++) {
            if (j == w[tmp[j]]) {
                result[tmp[j]]++;
            }
        }    
    }

    for (int i = 0; i < n; i++) {
        // cout << result[i] << ' ';
        printf("%d ", result[i]);
    }

    // cout << endl;
    printf("\n");

    return 0;
}