#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 400;
bool flag[maxN] = {false};
vector<int> e[maxN];
bool flag2 = false;
int c[maxN] = {0};
void dfs(int u, int tmp) {
	if (flag2) {
		return;
	}
	
	if (flag[u]) {
		if (c[u] != tmp) {
			flag2 = true;
			return;
		}
		return;
	}
	flag[u] = true;
	
	c[u] = tmp;
	for (int i = 0; i < e[u].size(); i++) {
		if (e[u][i] != u) {
			dfs(e[u][i], 1 - tmp);
		}
	}
}

int main()
{
	int k = 0;
	cin >> k;
	
	for (int i = 0; i < k; i++) {
		int n = 0;
		cin >> n;

		for (int j = 0; j < n; j++) {
			e[j].clear();
		}
		
		for (int j = 0; j < n; j++) {
			for (int l = 0; l < n; l++) {
				int num = 0;
				cin >> num;
				
				if (num == 1) {
					e[j].push_back(l);
				}
			}
		}
		
		memset(flag, false, sizeof(flag));
		flag2 = false;
		dfs(0, 0);	
		
		if (flag2) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
	
	return 0;
}