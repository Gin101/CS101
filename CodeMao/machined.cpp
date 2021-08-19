#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int max2N = 200001;
vector<int> e[max2N];
int l[max2N] = {0};//len
void bfs(int now) {
	queue<int> q;

	q.push(now);
    l[now] = 0;
	while (!q.empty()) {
		int tmp = q.front();
		q.pop();

		for (int i = 0; i < e[tmp].size(); i++) {
            if (l[e[tmp][i]] == -1) {
                q.push(e[tmp][i]), l[e[tmp][i]] = l[tmp] + 1;
            }
        }
	}
}
int main() 
{
    int n = 0;
    int m = 0;
    int q = 0;
    cin >> n >> m >> q;

	for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        cin >> u >> v; 

		e[u + n].push_back(v);
		e[v + n].push_back(u);
		e[u].push_back(v + n);
		e[v].push_back(u + n);
	}

	memset(l, -1, sizeof(l));
	bfs(1);

	for (int i = 0; i < q; i++) {
		int a = 0;
        int l2 = 0;
        cin >> a >> l2;

		if (l[a + (l2 % 2) * n] <= l2 && l[a + (l2 % 2) * n] != -1) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
	}
	return 0;
}