#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int maxN = 100;
const int maxX = 1e6 + 1;
const int INF = 0x3f3f3f3f;
int c[maxN] = {0};
int dp[maxX] = {0};

int main() 
{
    int n = 0;
    int x = 0;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    memset(dp, INF, sizeof(dp));

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = c[i]; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    if (dp[x] == INF) {
        cout << -1 << endl;
    } else {
        cout << dp[x] << endl;
    }

    return 0;
}