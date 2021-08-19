#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 2000;

double e[maxN][maxN] = {{0}};
double dp[maxN] = {0};
int num[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y >> e[x - 1][y - 1];

        e[x - 1][y - 1] = (100 - e[x - 1][y - 1]) / 100;
        e[y - 1][x - 1] = e[x - 1][y - 1];
    }

    int a = 0;
    int b = 0;
    cin >> a >> b;

    for (int i = 0; i < n; i++) {
        dp[i] = e[a - 1][i];
    }  

    dp[a - 1] = 1;
    num[a - 1] = 1;

    for (int i = 0; i < n - 1; i++) {
        double tmp = 0;
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (num[j] == 0 && dp[j] > tmp) {
                idx = j;
                tmp = dp[j];
            }
        }

        num[idx] = 1;
        if (idx != b - 1) {
            for (int j = 0; j < n; j++) {
                if (num[j] == 0 && dp[idx] * e[idx][j] > dp[j]) {
                    dp[j] = dp[idx] * e[idx][j];
                }
            }
        }
    }

    printf("%.8lf\n", 100 / dp[b - 1]);

    return 0;
}