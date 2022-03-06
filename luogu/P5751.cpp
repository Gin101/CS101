#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int maxN = 1001;
const int INF = 0x3f3f3f3f;
int dis[maxN] = {0};
int g[maxN][maxN] = {{0}};
int cnt[maxN] = {0};
queue<int> q;
bool flag[maxN] = {false};

int main()
{
	int n = 0;
	int a0 = 0;
	int b0 = 0;
	int l0 = 0;
	int a1 = 0;
	int b1 = 0;
	int l1 = 0;
	cin >> n >> a0 >> b0 >> l0 >> a1 >> b1 >> l1;
	
	memset(g, INF, sizeof(g));
	for (int i = 0; i <= n - l0; i++) {
		g[i][i + l0] = min(l0 - a0, g[i][i + l0]);
		g[i + l0][i] = min(b0 - l0, g[i + l0][i]);
	}
    
    for(int i = 0; i <= n - l1; i++) {
		g[i][i + l1] = min(b1, g[i][i + l1]);
		g[i + l1][i] = min(-a1, g[i + l1][i]);
    }
    
    for(int i = 1; i <= n; ++i) {
		g[i - 1][i] = min(g[i - 1][i], 1);
		g[i][i - 1] = min(g[i][i - 1], 0);
    }
    
    memset(dis, INF, sizeof(dis));
    dis[0] = 0;
		
    q.push(0);
    while(!q.empty()) {
        flag[q.front()] = false;
        for (int i = 0; i <= n; i++) {
            if (g[q.front()][i] != INF) {
                if (dis[i] > dis[q.front()] + g[q.front()][i]) {
                    cnt[i]++;
                    if (cnt[i] == n) {
                        cout << -1 << endl;
                        return 0;
                    }
                    dis[i] = dis[q.front()] + g[q.front()][i];
                    if (!flag[i]) { 
                        flag[i] = true;
                        q.push(i); 
                    }
                }
            }
        }

        q.pop();
    }
    
    cout << dis[n] << endl;

	return 0;
}