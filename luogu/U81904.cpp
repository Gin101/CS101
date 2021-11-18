#include <iostream>
#include <vector>

using namespace std;

struct Edge {
	int next, val;
} t;

const int maxN = 500001;
int s[maxN] = {0};
int result = 0;
vector<Edge> e[maxN];
bool flag[maxN] = {false};
int dfs(int k) {
	s[k] = 0;
	for (int i = 0; i < e[k].size(); i++) {
		s[k] = max(s[k], dfs(e[k][i].next) + e[k][i].val);
	}
	
	int d = 0;
	int d2 = 0;
	for (int i = 0; i < e[k].size(); i++) {
		int tmp = s[e[k][i].next] + e[k][i].val;
		if (tmp >= d) {
			d2 = d;
			d = tmp;
		} else if (tmp >= d2) {
			d2 = tmp;
		}
	}
	
	result = max(result, d + d2);
	
	return s[k];
}

int main()
{
	int n = 0;
	cin >> n;

	int root = 0;
    flag[0] = true;
	for (int i = 1; i < n; i++) {
		int u = 0;
        int v = 0;
        int w = 0;
        cin >> u >> v >> w;

        t.val = w;
        if (flag[u - 1]) {
            flag[v - 1] = true;
            t.next = v - 1;
            e[u - 1].push_back(t);
        } else {
            flag[u - 1] = true;
            t.next = u - 1;
            e[v - 1].push_back(t);
        }
	}
	
	dfs(0);
	
	cout << result << endl;
	
	return 0;
}