#include <iostream>
#include <stdio.h>

using namespace std;

const int maxN = 1001;
const int maxS = 1001;
double dp[maxN][maxS] = {{0}};

int main() 
{
    int n = 0;
    int s = 0;
    cin >> n >> s;
    
    for (int i = n; i >= 0; i--) {
        for (int j = s; j >= 0; j--) {
            if (i == n && s == j) {
                continue;
            }
            dp[i][j] = (dp[i][j + 1] * i * (s - j) + dp[i + 1][j] * (n - i) * j + dp[i + 1][j + 1] * (n - i) * (s - j) + n * s) / (n * s - i * j);
        }
    }

    printf("%.4lf\n", dp[0][0]);
  
    return 0;
}