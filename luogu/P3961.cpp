#include <iostream>

using namespace std;

const int maxN = 200;
const int maxT = 4e4;
int ti[maxN] = {0};
int v[maxN] = {0};
int dp[maxN][maxT] = {0};

int main() 
{
    int n = 0;
    int t = 0;
    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y >> ti[i] >> v[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= t; j++) {
            if (j >= ti[i]) {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - ti[i]] + v[i]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][t] << endl;

    return 0;
}