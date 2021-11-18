#include <iostream>
#include <queue>

using namespace std;

const int maxN = 500;
const int maxM = 500;
char c[maxN][maxM] = {{0}};
bool flag[maxN][maxN] = {{0}};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    queue<pair<int, int> > q;
    int r = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];

            if (c[i][j] == 's') {
                q.push(make_pair(i, j));
            } else if (c[i][j] == 'g') {
                r = i;
                c = j;
            }
        }
    }

    return 0;
}