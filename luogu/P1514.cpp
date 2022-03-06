#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
const int maxN = 500;
const int maxM = 500;
int h[maxN][maxM] = {{0}};
int num[maxM] = {0};
bool flag[maxN][maxM] = {{false}};
vector<int> tmp[maxM];

struct City {
    int row = 0;
    int col = 0;
};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }

    queue<City> q;// BFS queue
    // start BFS
    for (int i = 0; i < m; i++) {
        q.push((City){0, i});
        memset(flag, false, sizeof(flag));
        while (!q.empty()) {
            int r = q.front().row;
            int c = q.front().col;

            q.pop();
            if (flag[r][c]) {
                continue;
            }
            flag[r][c] = true;

            if (r == n - 1) {
                tmp[i].push_back(c);
            }

            for (int j = 0; j < 4; j++) {
                int newr = r + dr[j];
                int newc = c + dc[j];
                if (newr < 0 || newr == n || newc < 0 || newc == m) {
                    continue;
                }

                if (h[r][c] > h[newr][newc]) {
                    q.push((City){newr, newc});
                }
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < tmp[i].size(); j++) {
            num[tmp[i][j]]++;
        }
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        if (num[i] > 0) {
            result++;
        }
    }
    
    if (result != m) {
        cout << 0 << endl << m - result << endl;
    } else {
        result = m;
        for (int i = 0; i < m; i++) {
            bool flag2 = true;
            for (int j = 0; j < tmp[i].size(); j++) {
                if (num[tmp[i][j]] <= 1) {
                    flag2 = false;
                    break;
                }
            }

            if (flag2) {
                for (int j = 0; j < tmp[i].size(); j++) {
                    num[tmp[i][j]]--;
                }
                result--;
            }
        }

        cout << 1 << endl << result << endl;
    }

    return 0;
}