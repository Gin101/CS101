#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxHW = 100;
int c = 0;
int b = 0;
int dr[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, -1, 0, 1};
pair<int, int> pa[maxHW][maxHW];
bool flag[maxHW][maxHW][500] = {{{false}}};
struct Sea {
    int r = 0;
    int c = 0;
    int cnt = 0;
} tmp;
queue<Sea> q;

bool check(int row, int col, int ncnt) {
    int tmp = abs(pa[row][col].first + pa[row][col].second * ncnt) % (c * 2);
    if (tmp > c) {
        return (c * 2 - tmp) >= b;
    } else {
        return tmp >= b;
    }
}

int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w >> c >> b;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            char op;
            cin >> pa[i][j].first >> op;
            pa[i][j].second = op == '+' ? 1 : -1;

            if (i == 0 && j == 0) {
                q.push(tmp);
            }
        }
    }

    int result = INT_MAX;
    while (!q.empty()) {
        if (q.front().cnt + 1 >= result) {
            flag[q.front().r][q.front().c][q.front().cnt] = false;
            q.pop();
            continue;
        }
        for (int i = 0; i < 5; i++) {
            int nr = q.front().r + dr[i];
            int nc = q.front().c + dc[i];

            if (nr == h - 1 && nc == w - 1 && check(h - 1, w - 1, q.front().cnt + 1)) {
                result = min(result, q.front().cnt + 1);
            } else if (nr >= 0 && nr < h && nc >= 0 && nc < w && !flag[nr][nc][q.front().cnt + 1] && check(nr, nc, q.front().cnt + 1)) {
                tmp.r = nr;
                tmp.c = nc;
                tmp.cnt = q.front().cnt + 1;
                q.push(tmp);
                flag[nr][nc][q.front().cnt + 1] = true;
            }
        }

        flag[q.front().r][q.front().c][q.front().cnt] = false;
        q.pop();
    }

    if (result == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}