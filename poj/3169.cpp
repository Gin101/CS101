#include <iostream>
#include <vector>
#include <cstring>
#include <limits.h>
#include <algorithm>

using namespace std;

const int maxN = 1000;
const int INF = 0x3f3f3f3f;
struct Edge {
    int val;
    int idx;
} tmp;
vector<Edge> e[maxN];
int dis[maxN] = {0};
bool flag[maxN] = {false};

int main()
{
    int n = 0;
    int ml = 0;
    int md = 0;
    cin >> n >> ml >> md;

    for (int i = 0; i < ml; i++) {
        int a = 0;
        int b = 0;
        int d = 0;
        cin >> a >> b >> d;

        tmp.val = d;
        tmp.idx = b - 1;
        e[a - 1].push_back(tmp);
    }

    for (int i = 0; i < md; i++) {
        int a = 0;
        int b = 0;
        int d = 0;
        cin >> a >> b >> d;

        tmp.val = -d;
        tmp.idx = a - 1;
        e[b - 1].push_back(tmp);
    }

    memset(dis, INF, sizeof(dis));
    dis[0] = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        flag = false;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < e[j].size(); k++) {
                if (dis[e[j][k].idx] > dis[j] + e[j][k].val) {
                    dis[e[j][k].idx] = dis[j] + e[j][k].val;
                    flag = true;
                }
            }
        }   

        if (!flag) {
            if (dis[n - 1] == INF) {
                cout << -2 << endl;
            } else {
                cout << dis[n - 1] << endl;
            }

            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}