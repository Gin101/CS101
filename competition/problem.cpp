#include <iostream>
#include <cstring>

using namespace std;

const int maxN = 2001;
int dp[maxN][maxN] = {{0}};
int dp2[maxN][maxN] = {{0}};
int main() {
	int t = 0;
	int k = 0;
    
    cin >> t >> k;
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));
    dp[1][1] = 1;
    
    for (int i = 0; i <= 2000; i++) {
    	dp[i][0] = 1;
    }
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % k;
        }
    }
    for (int i = 2; i <= 2000; i++) {
        for (int j = 1; j <= i; j++) {
            dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1] - dp2[i - 1][j - 1];
            if (dp[i][j] == 0) {
            	dp2[i][j] += 1;
            }
        }
        dp2[i][i + 1] = dp2[i][i];
    }
    
    while(t--) {
    	int n = 0;
		int m = 0;
        cin >> n >> m;
        
        if(m > n) {
        	m = n;
        }
        
        cout << dp2[n][m] << endl;
    }    
    
    return 0;
} 