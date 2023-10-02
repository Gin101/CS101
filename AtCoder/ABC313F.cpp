#include <iostream>
#include <algorithm>
#include <limits.h>
#include <cstring>

using namespace std;

const int maxV = 3005;
const int maxP = 301;
const int INF = 0x3f3f3f3f;

int l[maxV] = {0};
int dp[maxV][maxP] = {{0}};
int dis[maxV][maxP] = {{0}};
int w[maxV][maxV] = {{0}};

int main() 
{
    int v = 0;
    int p = 0;
    cin >> v >> p;

    for (int i = 1; i <= v; i++) {
        cin >> l[i];
    }
	
    for (int i = 1; i <= v; i++) {
        w[i][i] = 0;
        for (int j = i + 1; j <= v; j++) {
            w[i][j] = w[i][j - 1] + l[j] - l[(i + j) / 2];
        }
    }
    
    sort(l + 1, l + v + 1);
    memset(dp, INF, sizeof(dp));
	dp[0][0] = 0;

    for (int i = 1; i <= p; i++) {
        dis[v + 1][i] = v;
        for (int j = v; j >= 1; j--) {
            int tmp = INT_MAX;
            int idx = 0;
            for (int k = dis[j][i - 1]; k <= dis[j + 1][i]; k++) {
                if (dp[k][i - 1] + w[k + 1][j] < tmp) {
                    tmp = dp[k][i - 1] + w[k + 1][j];
                    idx = k;
                }
            }
            dp[j][i] = tmp;
            dis[j][i] = idx;
        }
    }
	
    cout << dp[v][p] << endl;
	
	return 0;
}