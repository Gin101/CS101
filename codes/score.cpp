#include <iostream>

using namespace std;

int dp[25][5] = {{0}};

int main()
{
    for (int i = 0; i <= 5; i++) {
        dp[0][i] = 1;
    }

    for (int i = 1; i <= 25; i++) {
        for (int j = 1; j <= 5; j++) {
            for (int k = 0; k <= 5; k++) {
                if ((j == 5 && i == k) || (j != 5 && i >= k)) {
                    dp[i][j] += dp[i - k][j - 1];
                }
            }
        }
    }

    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        float need = 0;
        cin >> need;

        need *= 5;

        cout << dp[int(need)][5] << endl;
    }


}