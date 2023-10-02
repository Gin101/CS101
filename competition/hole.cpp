#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int INF = 0x3f3f3f3f;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
queue<pair<int, int> > q; 
queue<pair<int, int> > w;
char graph[50][50];
int t[50][50] = {{0}};
bool flag[50][50] = {{false}};
int result[50][50] = {{0}};

int main()
{
    int r = 0;
    int c = 0;
    cin >> r >> c;

    memset(t, INF, sizeof(t));
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == 'S') {
                q.push(make_pair(i, j));
            } 
            if (graph[i][j] == '*') {
                w.push(make_pair(i, j));
                flag[i][j] = true;
                t[i][j] = 0;
            }
        }
    }

    while (!w.empty()) {
        for (int i = 0; i < 4; i++) {
            int nr = w.front().first + dr[i];
            int nc = w.front().second + dc[i];

            if (nr >= 0 && nr < r && nc >= 0 && nc < c && graph[nr][nc] != 'X' && graph[nr][nc] != 'D' && !flag[nr][nc]) {
                w.push(make_pair(nr, nc));
                flag[nr][nc] = true;
                t[nr][nc] = t[w.front().first][w.front().second] + 1;
            }
        }
        w.pop();
    } 

    memset(flag, false, sizeof(flag));
    flag[q.front().first][q.front().second] = true;
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nr = q.front().first + dr[i];
            int nc = q.front().second + dc[i];
            if (graph[nr][nc] == 'D') {
                cout << result[q.front().first][q.front().second] + 1 << endl;
                return 0;
            }
            if (nr >= 0 && nr < r && nc >= 0 && nc < c && graph[nr][nc] != 'X' && !flag[nr][nc] && result[q.front().first][q.front().second] + 1 < t[nr][nc]) {
                q.push(make_pair(nr, nc));
                flag[nr][nc] = true;
                result[nr][nc] = result[q.front().first][q.front().second] + 1;
            }
        }
        q.pop();
    }

    cout << "NO" << endl;

    return 0;
}