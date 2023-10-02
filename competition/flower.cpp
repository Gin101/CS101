#include <iostream>
#include <cstring>
#pragma GCC

using namespace std;

int n = 0;
int m = 0;
const int maxN = 10;
const int maxM = 10;
bool flag[maxN][maxM] = {{false}};
int r[4] = {-1, 0, 0, 1};
int c[4] = {0, -1, 1, 0};
int result = 0;
bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!flag[i][j]) {
                return false;
            }
        }
    }

    return true;
}

bool check2() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!flag[i][j] && i != j) {
                return false;
            }
        }
    }

    return true;
}

void dfs(int row, int col) {
    if (row == 0 && col == 0 && check()) {
        result++;
        return;
    }

    if (flag[0][1] && flag[1][0] && !check2()) {
        return;
    }

    for (int i = 0; i < 4; i++) {
        int newr = row + r[i];
        int newc = col + c[i];
        if (newr >= 0 && newr < n && newc >= 0 && newc < m) {
            if (!flag[newr][newc]) {
                flag[newr][newc] = true;
                dfs(newr, newc);
                flag[newr][newc] = false;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;

    dfs(0, 0);

    cout << result << endl;

    return 0;
}