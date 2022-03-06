#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int maxN = 20001;
vector<int> e[maxN];
vector<int> e2[maxN];
int dis[maxN] = {0};
int p[maxN] = {0};
int result = 0;
int len = 0;

void dfs(int x, int f) {
	for (int i = 0; i < e[x].size(); i++) {
		int y = e[x][i];
		if (y != f) {
			p[y] = e2[x][i];
			dfs(y, x);
			dis[x] = max(dis[x], dis[y] + e2[x][i]);
		}
	}
	
	if (dis[x] + p[x] >= len) {
		result++;
		dis[x] = 0;
	}
}

int main()
{
	int n = 0;
	cin >> n;
	
	int mx = 0;
	for (int i = 1; i <= n; i++) {
		int m = 0;
		cin >> m;
		
		for (int j = 1; j <= m; j++) {
			int u = 0;
			int v = 0;
			cin >> u >> v;
			 
			e[i].push_back(u);
			e2[i].push_back(v);
			
			mx = max(mx, v);
		}
	}
	
	cin >> len;
	
	dfs(1, 0);
	
	if (mx >= len) {
		cout << "No solution." << endl;
	} else {
		cout << result << endl;
	}
	
	return 0;
}
	
