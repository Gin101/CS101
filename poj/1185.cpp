#include <iostream>

using namespace std;
const int maxN = 101;
const int maxM = 11;
const int maxS = 65;
int dp[maxN][maxS][maxS] = {{{0}}};
int pl[maxN] = {0};// the line before the pre line
int p[maxN] = {0};// pre line
int t[maxN] = {0};// this line
bool flag[maxN][maxM] = {{false}};

int main() 
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;

            if (c == 'H') {
                flag[i][j] = true;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pl[i] = (pl[i] << 1) + flag[i][j];
        }
    }

    int idx = 0;
    t[++idx] = 0;
    
    for (int i = 1; i < (1 << m); i++) {
        if ((i & (i << 1)) || (i & (i << 2)) || (i & (i >> 1)) || (i & (i >> 2))) {
            continue;
        }

        t[++idx] = i;
        int tmp = i;
        while (tmp) { 
            p[idx]++;
            tmp -= (tmp & (-tmp));
        }
    }

    int result = 0;

    cout << result << endl;

    return 0;
}