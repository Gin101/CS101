#include <iostream>
#include <string>

using namespace std;

const int maxM = 201;
const int maxK = 201;
const int MOD = 1e9 + 7;
long long dp[maxM][maxK] = {1};
long long sum[maxM][maxK] = {{0}};
char a[1001],b[201];
int main()
{
    int n = 0;
    int m = 0;
    int k = 0;
    string a;
    string b;
    cin >> n >> m >> k >> a >> b;

    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            for (int l = k; l >= 1; l--) {
                sum[j][l] = a[i - 1] == b[j - 1] ? sum[j - 1][l] + dp[j - 1][l - 1] : 0;
                dp[j][l] += sum[j][l];
                dp[j][l] %= MOD;
            }
        }
    }

    cout << dp[m][k] << endl;

    return 0;
}