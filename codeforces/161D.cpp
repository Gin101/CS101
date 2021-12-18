#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int k = 0;
const int maxN = 5e4 + 1;
const int maxK = 501;
vector<int> e[maxN];
int p[maxN] = {0};
int dis[maxN][maxK] = {{0}};
int s[maxK] = {0};

void dfs(int u, int pre){
	dis[u][0] = 1;
	p[u] = pre;
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != pre) {
			dfs(e[u][i], u);
			for (int j = 1; j <= k; j++) {
				if (dis[e[u][i]][j - 1] == 0) {
					break;
				}

				dis[u][j] += dis[e[u][i]][j - 1];
			}
		}	
	}
}

int main()
{
    int n = 0;
    cin >> n >> k;

	for (int i = 1; i < n; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v;

		e[u - 1].push_back(v - 1);
		e[v - 1].push_back(u - 1);
	}
	
	dfs(0, 0);
	
    int result = 0;
	for (int i = 0; i < n; i++) {
		memset(s, 0, sizeof(s));
		s[0] = 1;
		for (int j = 0; j < e[i].size(); j++) {
			if (e[i][j] == p[i]) {
                continue;
            }

			for (int l = 1; l <= k; l++) {
				result += dis[e[i][j]][l - 1] * s[k - l];
			}

			for (int l = 1; l <= k; l++) {
                s[l] += dis[e[i][j]][l - 1];
            }
		}	
	}
	
	cout << result << endl;
	
	return 0;
}