#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int maxN = 3001;
int dis[maxN][maxN] = {{0}};
vector<int> e[maxN];
queue<int> q;
int main () 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        e[x].push_back(y);
        e[y].push_back(x);
    }

	for (int i = 1; i <= n; i++) {
		q.push(i);
		while (!q.empty()) {
            for (int j = 0; j < e[q.front()].size(); j++) {
                if (dis[i][e[q.front()][j]] == 0 && e[q.front()][j] != i) {
                    q.push(e[q.front()][j]);
                    dis[i][e[q.front()][j]] = dis[i][q.front()] + 1;
                }
            }
            q.pop();
		}
	}

    int s1 = 0;
    int t1 = 0;
    int l1 = 0;
    int s2 = 0;
    int t2 = 0;
    int l2 = 0;
    cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;

	if (dis[s1][t1] > l1 || dis[s2][t2] > l2) {
        cout << -1 << endl;
		return 0;
	}

	int result = dis[s1][t1] + dis[s2][t2];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp = min(dis[i][s1], dis[j][s1]) + min(dis[i][t1], dis[j][t1]);
            int tmp2 = min(dis[i][s2], dis[j][s2]) + min(dis[i][t2], dis[j][t2]);

            if (tmp + dis[i][j] <= l1 && tmp2 + dis[i][j] <= l2) {
                result = min(result, tmp + tmp2 + dis[i][j]);
            }
        }
    }

    cout << m - result << endl;

    return 0;
}