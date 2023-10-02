#include <iostream>
#include <cstring>

#define g(i,l,r) for(int i=l;i<=r;i++)
using namespace std;

const int maxN = 301;
const int INF = 0x3f3f3f3f;
int a[maxN] = {0};
int p[maxN] = {0};
int f[maxN] = {0};
int e[maxN][maxN][maxN] = {{{0}}};
int result = INF;

void ope(int &x, int y) {
    x > y ? x = y : 1;
}
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; i++) {
        cin >> f[i] >> p[i];
    }
	
    memset(e, INF, sizeof(e));
	e[0][m][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m; k++) {
                int tmp = a[i] - a[i - 1];
                int x = j - tmp;
                int y = k + tmp;
                int q = e[i - 1][j][k];
                if (x < 0 || y > m) {
                    break;
                }

                ope(e[i][x][y], q);
                ope(e[i][min(m, x + p[i])][y], q + f[i]);
                ope(e[i][x][max(0, y - p[i])], q + f[i]);
            }
        }
    }

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m; j++) {
            if (i >= j) {
                ope(result, e[n][i][j]);
            }
        }
    }

    if (result == INF) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}