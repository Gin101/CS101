#include <iostream>
#include <stdio.h>

using namespace std;

typedef long long ll;

const int maxW = 1001;
const int maxB = 1001;
double dp[maxW][maxB] = {{0}};

int main() 
{
    int w = 0;
    int b = 0;
    cin >> w >> b;

    for (int i = 1; i <= w; i++) {
        dp[i][0] = 1;
    }
    for (int i = 1; i <= b; i++) {
        dp[0][i] = 0;
    }
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= b; j++) {
            dp[i][j] += (double)i / (i + j);
            if (j >= 3) {
                dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * (j - 2) / (i + j - 2) * dp[i][j - 3];
            }
            if (i >= 1 && j >= 2) {
                dp[i][j] += (double)j / (i + j) * (j - 1) / (i + j - 1) * i / (i + j - 2) * dp[i - 1][j - 2];
            }
        }
    }

    printf("%.9lf\n", dp[w][b]);
  
    return 0;
}