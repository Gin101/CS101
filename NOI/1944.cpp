#include <iostream>

using namespace std;


const int maxN = 20;
int dp[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;
    
    dp[0] = 1;
    dp[1] = 2;
    for (int i = 2; i < n;i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    cout << dp[n - 1] << endl;;
    
    return 0;
}