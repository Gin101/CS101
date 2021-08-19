#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n = 0;
int h = 0;
long long r = 0;
const int maxN = 1000;
long long x[maxN] = {0};
long long y[maxN] = {0};
long long z[maxN] = {0};
bool flag[maxN] = {false};
vector<int> e[maxN];
void bfs() {
	queue<int> q;

	for (int i = 0; i < n; i++) {
		if (z[i] <= r) {
			q.push(i);
			flag[i] = true;
		}
	}
	
	while (!q.empty()) {
		int tmp = q.front();
		
		if (z[tmp] + r >= h) {
			cout << "Yes" << endl;
			return;
		}
		q.pop();
		
		for (int i = 0; i < e[tmp].size(); i++) {
			if (!flag[e[tmp][i]]) {
				q.push(e[tmp][i]);
				flag[e[tmp][i]] = true;
			}
		}
	}
	
	cout << "No" << endl;
}

int main()
{
	int t = 0;
	cin >> t;
	
	for (int i = 0; i < t; i++){
		cin >> n >> h >> r;
		
		for (int j = 0; j < n; j++) {
			cin >> x[j] >> y[j] >> z[j];
			e[j].clear();
		}
		
		for (int j = 0; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				unsigned long long tmp = 0;
				tmp += (x[j] - x[k]) * (x[j] - x[k]);
				tmp += (y[j] - y[k]) * (y[j] - y[k]);
				tmp += (z[j] - z[k]) * (z[j] - z[k]);
				
				if (tmp <= 4 * r * r) {
					e[j].push_back(k);
					e[k].push_back(j);
				}
			}
		}
		memset(flag, false, sizeof(flag));
		bfs();
	}
	
	return 0;
}