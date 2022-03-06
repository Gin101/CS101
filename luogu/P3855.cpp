#include <iostream>
#include <queue>

using namespace std;

const int maxR = 30;
const int maxC = 30;
char g[maxR][maxC];
bool flag[maxR][maxC][maxR][maxC] = {{false}};
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int dc2[4] = {0, 1, -1, 0};

struct Dot {
    int row = 0;
    int col = 0;
    int row2 = 0;
    int col2 = 0;
    int step = 0;
} tmp;

queue<Dot> q;

int main()
{
    int r = 0;
    int c = 0;
    cin >> r >> c;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> g[i][j];
            if (g[i][j] == 'G') {
                tmp.row = i;
                tmp.col = j;
            } else if (g[i][j] == 'M') {
                tmp.row2 = i;
                tmp.col2 = j;
            }
        }
    }

    q.push(tmp);
    flag[tmp.row][tmp.col][tmp.row2][tmp.col2] = true;
    while (!q.empty()) {
        cout << q.front().row << ' ' << q.front().col << ' ' << q.front().row2 << ' ' << q.front().col2 << endl;
        for (int i = 0; i < 4; i++) {
            int newr = q.front().row + dr[i];
            int newc = q.front().col + dc[i];
            int newr2 = q.front().row2 + dr[i];
            int newc2 = q.front().col2 + dc2[i];

            if (g[newr][newc] == '#') {
                newr -= dr[i];
                newc -= dc[i];
            }
            if (g[newr2][newc2] == '#') {
                newr2 -= dr[i];
                newc2 -= dc2[i];
            }
            if (newr >= 0 && newr < r && newc >= 0 && newc < c && newr2 >= 0 && newr2 < r && newc2 >= 0 && newc2 < c && g[newr][newc] != 'X' && g[newr2][newc2] != 'X' && !flag[newr][newc][newr2][newc2]) {
                if (g[newr][newc] == 'T' && g[newr2][newc2] == 'T') {
                    cout << q.front().step + 1 << endl;
                    return 0;
                }

                tmp.row = newr;
                tmp.col = newc;
                tmp.row2 = newr2;
                tmp.col2 = newc2;
                tmp.step = q.front().step + 1;
                flag[tmp.row][tmp.col][tmp.row2][tmp.col2] = true;
                q.push(tmp);
            } 
        }

        q.pop();
    }

    cout << "No" << endl;

    return 0;
}