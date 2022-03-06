#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 150;
struct Dot {
    int x = 0;
    int y = 0;
}p[maxN];

double e[maxN][maxN] = {{0}};
double dp[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char c;
            cin >> c;
            if (c == '1') {
                int tmp = abs(p[i].x - p[j].x);
                int tmp2 = abs(p[i].y - p[j].y);
                e[i][j] = sqrt(tmp * tmp + tmp2 * tmp2);
                e[j][i] = e[i][j];
            } else {
                e[i][j] = INT_MAX;
                e[j][i] = INT_MAX;
            } 
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (i != j && j != k && i != k) {
                    e[j][k] = min(e[j][k], e[j][i] + e[i][k]);
                }
            }
        }
    }//special floyd

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (e[i][j] != INT_MAX) {
                dp[i] = max(dp[i], e[i][j]);
            }
        }
    }//dp[i] means all of the line link with dot "i" 's max

    double result = INT_MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && e[i][j] == INT_MAX) {
                int tmp = abs(p[i].x - p[j].x);
                int tmp2 = abs(p[i].y - p[j].y);
                result = min(result, dp[i] + dp[j] + sqrt(tmp * tmp + tmp2 * tmp2));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        result = max(result, dp[i]);
    }

    printf("%.6lf\n", result);

    return 0;
}