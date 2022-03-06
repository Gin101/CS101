#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

const int maxN = 3000;
double p[maxN] = {0};
double dp[maxN][maxN] = {{0}};

int main() 
{
    int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
	
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j > 0) {
                dp[i][j] += dp[i - 1][j - 1] * p[i];
            }
			dp[i][j] += dp[i - 1][j] * (1 - p[i]);
		}
	}
	
	double result = 0;
	for (int i = ceil(n / 2.0); i <= n; i++) {
        result += dp[n][i];
    }
	
    printf("%.9lf\n", result);
	
	return 0;
}