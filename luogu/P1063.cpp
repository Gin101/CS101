#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 201;

int e[maxN] = {0};
int dp[maxN][maxN] = {{0}};
int main()
{
	int n = 0;
	cin >> n;
    
    for (int i = 1; i <= n; i++) { 
    	cin >> e[i];
    	e[i + n] = e[i];
    }
    
    int result = 0;
    for (int i = 2; i < 2 * n; i++) {
        for (int j = i - 1; i - j < n && j >= 1; j--) {
            for (int k = j; k < i; k++) {
            	dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + e[j] * e[k + 1] * e[i + 1]);
            }
            
            result = max(result, dp[j][i]);
        }
    } 
    
    cout << result << endl;
    
    return 0;
}