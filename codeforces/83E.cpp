#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int maxS = 21;
const int INF = 0x3f3f3f3f;
int num[1 << maxS] = {0};
int dp[1 << maxS][maxS] = {{0}};
int main()
{
    int n = 0;
    cin >> n;

    int size = 0;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;

        size = size ? 0 : s.size();
        for (int j = 0; j < size; j++) {
            num[i] = num[i] * 2 + s[j] - 48;
        }
    }

    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i) {
            int result = INF;
            int idx = 0;
            while ((num[i - 1] & ~-(1 << size - idx)) != num[i] >> idx) {
                result += idx;
                idx++;
            }

            for (int j = 1; j <= size + 1; j++) {
                result = min(result, dp[num[i] >> j][size - j] + j - idx);
            }
            for (int j = 1; j <= size + 1; j++) {
                dp[num[i - 1] & ~-(1 << j)][j] = min(dp[num[i - 1] & ~-(1 << j)][j], result);
            }
        }
    }
	
    for (int i = 1; i <= 1 << size; i++) {
        for (int j = 1; j <= dp[i][j]; j++) {
            cout << j + result + size << endl;
            return 0;
        }
    }

    return 0;
}