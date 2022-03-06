#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int maxN = 1000;
const int maxM = 1000;
const int INF = 0x3f3f3f3f;
char g[maxN][maxM];
int dis[maxN][maxM][4] = {{{0}}};
int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};
deque<int> q; 

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> g[i][j];
        }
    }

    memset(dis, INF, sizeof(dis));
    dis[n - 1][m - 1][3] = 0;
    q.push_front(3);
    q.push_front(m - 1);
    q.push_front(n - 1);
    while (!q.empty()) { 
        int row = q[0];
        int col = q[1];
        int dir = q[2];
        q.pop_front();
        q.pop_front();
        q.pop_front();

        int newr = row + dr[dir];
        int newc = col + dc[dir];
        int newnum = dis[row][col][dir];

        if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
            if (newnum < dis[newr][newc][dir]) {
                dis[newr][newc][dir] = newnum;
                q.push_front(dir);
                q.push_front(newc);
                q.push_front(newr);
            }
        }

        if (g[row][col] == '#') {
            for (int i = 0; i < 4; i++) {
                if (i != dir) {
                    if (newnum + 1 < dis[row][col][i]) {
                        dis[row][col][i] = newnum + 1;
                        q.push_back(row);
                        q.push_back(col);
                        q.push_back(i);
                    }
                }
            }
        }
    }

    cout << (dis[0][0][3] == INF ? -1 : dis[0][0][3]) << endl;

    return 0;
}