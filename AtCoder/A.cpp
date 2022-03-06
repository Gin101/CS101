#include <iostream>

using namespace std;

const int maxN = 501;
const int maxK = 501;
int c[maxN] = {0};
bool dp[maxN][maxK] = {{false}};
bool flag[maxK] = {false};
bool flag2[maxK] = {false};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> c[i];
    }

    for (int i = 0; i <= n; i++) {
        dp[i][0] = true;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j >= c[i]) {
                dp[i][j] |= (dp[i - 1][j] | dp[i - 1][j - c[i]]);
            } else {
                dp[i][j] |= dp[i - 1][j];
            }
        }
    }

    int result = 0;
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            if (dp[j][i]) {
                flag[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i <= k / 2; i++) {
        if (flag[i] && flag[k - i]) {
            result += 2;
            flag2[i] = true;
            flag2[k - 1] = true;
        }
    }

    cout << result << endl;
    for (int i = 0; i <= k; i++) {
        if (flag2[i]) {
            cout << i << ' ';
        }
    }

    cout << endl;

    return 0;
}