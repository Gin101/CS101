#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 1e5 + 1;
const int maxM = 2e5 + 1;
int num[maxN] = {false};
int cnt[maxN] = {0};
vector<pair<int, int> > e[maxN];
queue<int> q;
double dp[maxN] = {0};

int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
        int u = 0;
        int v = 0;
        int w = 0;
        cin >> u >> v >> w;

        e[v - 1].push_back(make_pair(u - 1, w));
		num[u - 1]++; 
        cnt[u - 1]++;
	}
	
	q.push(n - 1);
	while (!q.empty()) {
		for (int i = 0; i < e[q.front()].size(); i++) {
			dp[e[q.front()][i].first] += (dp[q.front()] + e[q.front()][i].second) / cnt[e[q.front()][i].first];
			if (!(--num[e[q.front()][i].first])) {
				q.push(e[q.front()][i].first);
			}
		}

        q.pop();
	}
	
    printf("%.2lf\n", dp[0]);
	
	return 0;
}