#include <iostream> 
#include <algorithm>
#include <cstring>

using namespace std;

const int maxM = 1e4;
const int maxT = 1e7;
int a[maxM] = {0};
int b[maxM] = {0};
long long dp[maxT] = {0}; 

int main()
{
    int t = 0;
    int m = 0;
    cin >> t >> m;

    for (int i = 1; i <= m; i++) {
        cin >> a[i] >> b[i];
    }

    for (int i = 1; i <= m; i++) {
        for (int j = a[i]; j <= t; j++) {
            dp[j] = max(dp[j], dp[j - a[i]] + b[i]);
        }
    }

    cout << dp[t] << endl;

    return 0;
}