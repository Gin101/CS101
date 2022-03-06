#include <iostream>
#include <algorithm>
#include <string.h>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;
const int maxN = 500;
struct Edge {
    int next = 0;
    int val = 0;
} tmp;
vector<Edge> e[maxN];
int dis[maxN] = {0};
void relax(int u, int v, int weight) {
    if (dis[v] > dis[u] + weight)
        dis[v] = dis[u] + weight;
}
int main() 
{
    int f = 0;
    cin >> f;

    for (int i = 0; i < f; i++) {
        int n = 0;
        int m = 0;
        int w = 0;
        cin >> n >> m >> w;

        for (int j = 0; j < m; j++) { 
            int s = 0;
            int e2 = 0;
            int t = 0;
            cin >> s >> e2 >> t;

            tmp.next = e2 - 1;
            tmp.val = t;
            e[s - 1].push_back(tmp);
            tmp.next = s - 1;
            e[e2 - 1].push_back(tmp);
        }

        for (int j = 0; j < w; j++) {
            int s = 0;
            int e2 = 0;
            int t = 0;
            cin >> s >> e2 >> t;

            tmp.next = e2 - 1;
            tmp.val = -t;
            e[s - 1].push_back(tmp);
        }

        memset(dis, INF, sizeof(dis));
        dis[0] = 0;

        bool flag = false;
        for (int j = 0; j < n; j++) {
            flag = false;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < e[k].size(); l++) {
                    if (dis[e[k][l].next] > dis[k] + e[k][l].val) {
                        dis[e[k][l].next] = dis[k] + e[k][l].val;
                        flag = true;
                    }
                }
            }
            if (!flag) {
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}