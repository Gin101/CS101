#include <iostream>

using namespace std;

const int maxN = 33;
int num[maxN] = {0};
int dp[maxN][maxN] = {{0}};

int main()
{
    int n = 0;
    int p = 0;
    int c = 0;
    cin >> n >> p >> c;

    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j];
        }
    }

    return 0;
}