#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct Square {
    int r = 0;
    int c = 0;
    int val = 0;
    int cnt = 0;
} tmp;

const int maxHW = 300;
char s[maxHW][maxHW];
queue<Square> q;
int dr[4] = {0, -1, 0, 1};
int dc[4] = {-1, 0, 1, 0};

int main()
{
    int h = 0;
    int w = 0;
    int t = 0;
    cin >> h >> w >> t;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
            if (s[i][j] == 'S') {
                tmp.r = i;
                tmp.c = j;
                q.push(tmp);
            }
        }
    }

    int result = 0;
    bool flag = false;
    while (!q.empty()) {
        for (int i = 0; i < 4; i++) {
            int newr = q.front().r + dr[i];
            int newc = q.front().c + dc[i];
            if (newr >= 0 && newr < w && newc >= 0 && newc < h && s[newr][newc] != '#') {
                tmp.r = newr;
                tmp.c = newc;
                tmp.cnt = q.front().cnt + 1;
                if (tmp.cnt > t) {
                    q.pop();
                    continue;
                }
                if (s[newr][newc] == 'o') {
                    tmp.val = q.front().val + 1;
                } else if (s[newr][newc] == 'G') {
                    flag = true;
                    result = max(result, q.front().val);
                }
                q.push(tmp);
            }
        }
        q.pop();
    }

    if (flag) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}