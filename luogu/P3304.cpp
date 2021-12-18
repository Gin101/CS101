#include <iostream>
#include <vector>

using namespace std;

struct Node {
	int next = 0;
    int val = 0;
} tmp;

const int maxN = 2e5;
long long s[maxN] = {0};
long long result = 0;
vector<Node> e[maxN];
bool flag[maxN] = {false};
int f[maxN] = {0};
int idxd = 0;
int idxd2 = 0;
long long dfs(int u) {
	for (int i = 0; i < e[u].size(); i++) {
		s[u] = max(s[u], dfs(e[u][i].next) + e[u][i].val);
	}
	
	long long d = 0;
	long long d2 = 0;
    int tmpd = 0;
    int tmpd2 = 0;
	for (int i = 0; i < e[u].size(); i++) {
		long long tmp = s[e[u][i].next] + e[u][i].val;
		if (tmp >= d) {
			d2 = d;
			d = tmp;
            tmpd = u;
            tmpd2 = e[u][i].next;
		} else if (tmp >= d2) {
			d2 = tmp;
            if (tmpd != u) {
                tmpd2 = u;
            }
		}

        cout << d << ' ' << d2 << ' ' << tmpd << ' ' << tmpd2 << endl;
	}
	
    if (d + d2 > result) {
        result = d + d2;
        idxd = tmpd;
        idxd2 = tmpd2;
    }
	
	return s[u];
}

int main()
{
	int n = 0;
	cin >> n;

	int root = 0;
    flag[0] = true;
	for (int i = 1; i < n; i++) {
		int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;

        tmp.val = c;
        if (flag[a - 1]) {
            flag[b - 1] = true;
            tmp.next = b - 1;
            f[b - 1] = a - 1;
            e[a - 1].push_back(tmp);
        } else {
            flag[a - 1] = true;
            tmp.next = a - 1;
            f[a - 1] = b - 1;
            e[b - 1].push_back(tmp);
        }
	}
	
	dfs(0);
	
	cout << result << endl;

    cout << idxd << ' ' << idxd2 << endl;
	
	return 0;
}