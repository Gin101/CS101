#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int maxN = 2e3;
const int INF = 0x3f3f3f3f;
int dis[maxN] = {0};

struct Node {
    int v = 0;
    int w = 0;
} tmp;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        vector<Node> e[maxN];

        int n = 0;
        int m = 0;
        cin >> n >> m;

        for (int j = 0; j < m; j++) {
            int u = 0;
            int v = 0;
            int w = 0;
            cin >> u >> v >> w;

            if (w >= 0) {
                tmp.v = v - 1;
                tmp.w = w;
                e[u - 1].push_back(tmp);
                tmp.v = u - 1;
                tmp.w = w;
                e[v - 1].push_back(tmp);
            } else {
                tmp.v = v - 1;
                tmp.w = w;
                e[u - 1].push_back(tmp);
            }
        }

        memset(dis, INF, sizeof(dis));
        dis[0] = 0;

        bool flag = false;
        for (int j = 0; j < n; j++) {
            flag = false;
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < e[k].size(); l++) {
                    if (dis[e[k][l].v] > dis[k] + e[k][l].w && dis[k] != 0x3f3f3f3f) {
                        dis[e[k][l].v] = dis[k] + e[k][l].w;
                        flag = true;
                    }
                }
            }  

            if (!flag) {
                cout << "NO" << endl;
                break;
            }
        }

        if (flag) {
            cout << "YES" << endl;
        }
    }

    return 0;
}
