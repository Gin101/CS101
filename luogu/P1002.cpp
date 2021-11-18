#include <iostream>
#include <queue>

using namespace std;

const int maxN = 21;
const int maxM = 21;
bool flag[maxN][maxM] = {{false}};
int dr[8] = {-2, -2, -1, 1, 2, 2, 1, -1};
int dc[8] = {-1, 1, 2, 2, 1, -1, -2, -2};
int dr2[2] = {0, 1};
int dc2[2] = {1, 0};

int main()
{
    int n = 0;
    int m = 0;
    int n2 = 0;
    int m2 = 0;
    cin >> n >> m >> n2 >> m2;

    flag[n2][m2] = true;
    for (int i = 0; i < 8; i++) {
        int tmpr = n2 + dr[i];
        int tmpc = m2 + dc[i];

        if (tmpr >= 0 && tmpc >= 0 && tmpr <= n && tmpc <= m) {
            flag[tmpr][tmpc] = true;
        }
    }

    queue<pair<int, int> > q;
    q.push(make_pair(0, 0));

    int result = 0;
    while (!q.empty()) {
        for (int i = 0; i < 2; i++) {
            int tmpr = q.front().first + dr2[i];
            int tmpc = q.front().second + dc2[i];

            if (tmpr == n && tmpc == m) {
                result++;
                q.pop();

                continue;
            }

            if (tmpr <= n && tmpc <= m) {
                cout << tmpr << ' ' << tmpc << endl;
                if (!flag[tmpr][tmpc]) {
                    q.push(make_pair(tmpr, tmpc));
                }
            }
        }

        flag[q.front().first][q.front().second] = true;
        q.pop();
    }

    cout << result << endl;

    return 0;
}