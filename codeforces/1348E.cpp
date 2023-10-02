#include <iostream>

using namespace std;

const int maxN = 500;
const int maxK = 500;
bool dp[maxN][maxK] = {{false}};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    dp[0][0] = true;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        int r = 0;
        int b = 0;
        cin >> r >> b;

        sum += r + b;
        for (int j = 0; j < k; j++) {
            for (int l = 0; l < k; l++) {
                if (l <= r && (r + b - l) % k <= b) {
                    dp[i][j] |= dp[i - 1][(j - l + k) % k];
                }
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < k; i++) {
        if (dp[n][i]) {
            result = max(result, (sum - i - (sum - i) % k) / k);
        }
    }

    cout << result << endl;

    return 0;
}