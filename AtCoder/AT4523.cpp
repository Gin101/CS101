#include <iostream>

using namespace std;

const int maxN = 1e5;
const int INF = 0x3f3f3f3f;
int a[maxN] = {0};
int dp[maxN] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        dp[i] = INF;
        for (int j = 1; j <= k && i >= j; j++) {
            dp[i] = min(dp[i], abs(a[i] - a[i - j]) + dp[i - j]);
        }
    }

    cout << dp[n - 1] << endl;

    return 0;
}