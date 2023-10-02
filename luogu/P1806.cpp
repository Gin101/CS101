#include <iostream>

using namespace std;

const int maxN = 501;
long long dp[maxN] = {0};
int main()
{
    long long n = 0;
    cin >> n;

    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = n; j >= i; j--) {
            dp[j] += dp[j - i];
        }
    }

    cout << dp[n] - 1 << endl;
    
    return 0;
}