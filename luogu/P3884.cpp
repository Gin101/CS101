#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int maxN = 100;
vector<int> e[maxN];
vector<int> e2[maxN];
int b[maxN] = {0};
int d[maxN] = {0};
int f[maxN] = {0};
int rd = 0;

void dfs(int r, int deep) {
    d[r] = deep;
    rd = max(rd, deep);
	
	for (int i = 0; i < e[r].size(); i++) {
		dfs(e[r][i], deep + 1);
	}
}

int v = 0;
void dfs2 (int r, int pre, int cnt) {
    if (r == v - 1) {
        cout << cnt << endl;
        return;
    }

    for (int i = 0; i < e2[r].size(); i++) {
        if (e2[r][i] != pre) {
            if (f[r] == e2[r][i]) {
                dfs2(e2[r][i], r, cnt + 2);
            } else {
                dfs2(e2[r][i], r, cnt + 1);
            }
        }
    }
}

int main()
{
	int n = 0;
	cin >> n;
	
	for (int i = 1; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;
		
		e[x - 1].push_back(y - 1);
        e2[x - 1].push_back(y - 1);
        e2[y - 1].push_back(x - 1);
        f[y - 1] = x - 1;
	}

	dfs(0, 1);

	for (int i = 0; i < n; i++) {
		b[d[i] - 1]++;
	}
	
	sort(b, b + rd, greater<int>());

    int u = 0;
    cin >> u >> v;
	
	cout << rd << endl << b[0] << endl;
    dfs2(u - 1, u - 1, 0);
	
	return 0;
}