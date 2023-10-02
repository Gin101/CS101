#include <iostream>
#include <vector>

using namespace std;

const int maxN = 1e5 + 1;
int idx[maxN] = {0};
int f[maxN] = {0};
vector<int> e[maxN];
int num[maxN] = {0};
int result[maxN] = {0};
int cnt = 0;
void dfs(int u) {
	num[u] = ++cnt;
	result[u] = 1;

    for (int i = 0; i < e[u].size(); i++) {
        dfs(e[u][i]);
        result[u] += result[e[u][i]];
    }
}
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    int q = 0;
    cin >> n >> m >> k >> q;

    for (int i = 0; i < k; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        if (idx[b]) {
            e[idx[b]].push_back(a);
            f[a] = idx[b];
        }

        idx[b] = a;
    }

    for (int i = 1; i <= n; i++) {
        if (!f[i]) {
            dfs(i);
        }
    }
	
    for (int i = 0; i < q; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        if (!idx[y]) {
            cout << 0 << endl;
        } else {
            if (num[idx[y]] >= num[x] && num[idx[y]] < num[x] + result[x]) {
                cout << result[x] << endl;
            } else {
                cout << 0 << endl;
            }
        }
    }

	return 0;
}