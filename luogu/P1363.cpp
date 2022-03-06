#include <iostream>
#include <cstring>

using namespace std;

int n = 0;
int m = 0;
const int maxN = 1501;
const int maxM = 1501;
int num[maxN][maxN][2] = {{{0}}};//0 = row, 1 = col
bool flag[maxN][maxN] = {{false}};// judge is this dot can or can't visited
bool flag2[maxN][maxN] = {{false}};// judge is this road is visited
bool flag3 = false;// judge is the answer is "Yes" or "No"
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
void dfs(int row, int col, int tmpr, int tmpc) {
    if (flag3) {
        return;
    } // stop visiting

    // update the bool "flag3"
    if (flag2[row][col] && (num[row][col][0] != tmpr || num[row][col][1] != tmpc)) {
        flag3 = true;
        return;
    }

    // update the array "num" and "flag2"
    num[row][col][0] = tmpr;
    num[row][col][1] = tmpc;
    flag2[row][col] = true;

    for (int i = 0; i < 4; i++) {
        int newr = (row + dr[i] + n) % n;
        int newc = (col + dc[i] + m) % m;
        int newtr = tmpr + dr[i];
        int newtc = tmpc + dc[i];
        if (!flag[newr][newc] && (num[newr][newc][0] != newtr || num[newr][newc][1] != newtc || !flag2[newr][newc])) {
            dfs(newr, newc, newtr, newtc);
        }
    }
}

int main()
{
    while (cin >> n >> m) {
        memset(flag, false, sizeof(flag));
        memset(flag2, false, sizeof(flag2));
        memset(num, false, sizeof(num));
        flag3 = false;

        int sr = 0;
        int sc = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c;
                cin >> c;
                if (c == '#') {
                    flag[i][j] = true;
                } else if (c == 'S') {
                    sr = i;
                    sc = j;
                }
            }
        }

        dfs(sr, sc, sr, sc);

        if (flag3) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}