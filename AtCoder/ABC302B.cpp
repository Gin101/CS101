#include <iostream>
#include <queue>

using namespace std;

const int maxHW = 100;
char s[maxHW][maxHW];
struct Node {
    int r = 0;
    int c = 0;
    int r1 = 0;
    int c1 = 0;
    int r2 = 0;
    int c2 = 0;
    int r3 = 0;
    int c3 = 0;
    int r4 = 0;
    int c4 = 0;
    int choose = -1;
} tmp;
queue<Node>q;
int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> s[i][j];
            if (s[i][j] == 's') {
                tmp.r = i;
                tmp.c = j;
                tmp.r1 = i;
                tmp.c1 = j;
                q.push(tmp);
            }
        }
    }

    while (!q.empty()) {
        for (int i = 0; i < 8; i++) {
            if (q.front().choose != -1 && q.front().choose != i) {
                continue;
            }
            int nr = q.front().r + dr[i];
            int nc = q.front().c + dc[i];
            if (nr >= 0 && nr < h && nc >= 0 && nc < w) {
                tmp = q.front();
                tmp.r = nr;
                tmp.c = nc;
                switch (s[q.front().r][q.front().c]) {
                    case 's' : {
                        if (s[nr][nc] == 'n') {
                            tmp.r2 = nr;
                            tmp.c2 = nc;
                            tmp.choose = i;
                            q.push(tmp);
                        }
                        break;
                    } case 'n' : {
                        if (s[nr][nc] == 'u') {
                            tmp.r3 = nr;
                            tmp.c3 = nc;
                            q.push(tmp);
                        }
                        break;
                    } case 'u' : {
                        if (s[nr][nc] == 'k') {
                            tmp.r4 = nr;
                            tmp.c4 = nc;
                            q.push(tmp);
                        }
                        break;
                    } case 'k' : {
                        if (s[nr][nc] == 'e') {
                            cout << q.front().r1 + 1 << ' ' << q.front().c1 + 1 << endl << q.front().r2 + 1 << ' ' << q.front().c2 + 1 << endl << q.front().r3 + 1 << ' ' << q.front().c3 + 1 << endl << q.front().r4 + 1 << ' ' << q.front().c4 + 1 << endl << nr + 1 << ' ' << nc + 1 << endl;
                            return 0;
                        }
                    }
                }
            }
        }
        q.pop();
    }

    return 0;
}