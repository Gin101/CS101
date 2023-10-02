#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 250;
int dp[maxN][maxN] = {{0}};

int main() 
{
    int n = 0;
    cin >> n;

    int result = 0;
    for (int i = 1; i <= n; i++) {
        cin >> dp[i][i];
        result = max(result, dp[i][i]);
    }

    for (int i = 2; i <= n; i++) {
        for (int l = 1; i + l - 1 <= n; l++) {
            int r = l + i - 1;
            for (int j = l; j < r; j++) {
                if (dp[l][j] == dp[j + 1][r] && dp[l][j]) {
                    dp[l][r] = max(dp[l][r], dp[l][j] + 1);
                    result = max(result, dp[l][r]);
                }
            }
        }
    }
    
    cout << result << endl;
    	
    return 0;
} 