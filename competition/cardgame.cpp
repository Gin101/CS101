#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0;
const int maxN = 50;
char card[maxN][maxN];
int r[4] = {-1, 0, 0, 1};
int c[4] = {0, -1, 1, 0};
bool flag[maxN][maxN] = {{false}};
int result = 0;
void bfs(int row, int col) {
    queue<pair<int, int> > q;
    q.push({row, col});
    memset(flag, false, sizeof(flag));

    int tmp = 0;
    while (!q.empty()) {
        tmp++;
        for (int i = 0; i < 4; i++) {
            int newr = q.front().first + r[i];
            int newc = q.front().second + c[i];
            if (newr >= 0 && newr < n && newc >= 0 && newc < n) {
                if (!flag[newr][newc] && card[newr][newc] == 'A') {
                    q.push({newr, newc});
                    flag[newr][newc] = true;
                }
            }
        }
        q.pop();
    }

    result = max(result, tmp);
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> card[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (card[i][j] == 'B') {
                bfs(i, j);
            }
        }
    }

    cout << result << endl;

    return 0;
}