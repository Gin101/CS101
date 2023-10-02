#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 1001;
int p[maxN] = {0};
vector<vector<pair<int, int> > > e(maxN);
queue<int> q;
bool flag[maxN] = {false};
void dfs(int u) {
    q.push(u);
    flag[u] = true;

    for (auto[idx, i] : e[u]) {
        if (!flag[idx]) {
            dfs(idx);
        }
    }
}
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    int m = 0;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b;

        e[a].emplace_back(b, i);
        e[b].emplace_back(a, i);
    }

    for (int i = 1; i <= n; i++) {
        if (!flag[i]) {
            dfs(i)
;        }
    }

	reverse(q.begin(), q.end());
	vector<int>ok(n+1, 0), ans;
	for (auto s:q) {
		vis=ok;
		function<bool(int)>find=[&](int u) {
			vis[u]=1;
			if (p[u] == s)return 1;
			for (auto [v, i]:G[u]) {
				if (!vis[v]&&find(v)){
					ans.push_back(i);
					swap(p[u], p[v]);
					return 1;
				}
			}
			return 0;
		};
		if(!find(s)){cout<<-1<<endl;return 0;}
		ok[s]=1;
	}
	cout<<ans.size()<<endl;
	for(auto x:ans)cout << x << " ";
	return 0;
}