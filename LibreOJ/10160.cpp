#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e4 + 1;
int dp[maxN][2] = {{0}};
int main() 
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> dp[i][1];
    }

    int result = dp[1][1];
    for (int i = 1; i <= n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        if (x == 0 && y == 0) {
            break;
        }

        dp[y][1] += dp[x][0];
        dp[y][0] += max(dp[x][0], dp[x][1]);
        result = max(dp[y][0], max(result, dp[y][1]));
    }

    cout << result << endl;

    return 0;
}