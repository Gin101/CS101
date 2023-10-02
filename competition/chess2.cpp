#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int maxN = 1000;
int chess[maxN][maxN] = {{0}};
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, -1, 0, 1};
struct Chess {
    int r = 0;
    int c = 0;
    int val = 0;
    int cnt = 0;
} tmp;

queue<Chess> q;
int main()
{
    int n = 0;
    int R = 0;
    int C = 0;
    cin >> n >> R >> C;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> chess[i][j];
            if (i == R - 1 && j == C - 1) {
                tmp.r = i;
                tmp.c = j;
                tmp.val = chess[i][j];
                tmp.cnt = 1;
                q.push(tmp);
            }
        }
    }

    int result = 0;
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int nr = q.front().r + dr[i];
            int nc = q.front().c + dc[i];
            if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                if (i == 1 || i == 3) {
                    for (int j = 0; j < n; j++) {
                        if ((j != nr - 1) && (j != nr) && (j != nr + 1) && chess[j][nc] > q.front().val) {
                            tmp.r = j;
                            tmp.c = nc;
                            tmp.val = chess[j][nc];
                            tmp.cnt = q.front().cnt + 1;
                            q.push(tmp);
                        }
                    }
                } else {
                    for (int j = 0; j < n; j++) {
                        if ((j != nc - 1) && (j != nc) && (j != nc + 1) && chess[nr][j] > q.front().val) {
                            tmp.r = nr;
                            tmp.c = j;
                            tmp.val = chess[nr][j];
                            tmp.cnt = q.front().cnt + 1;
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        result = max(result, q.front().cnt);
        q.pop();
    }

    cout << result << endl;

    return 0;
}