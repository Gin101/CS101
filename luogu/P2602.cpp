#include <iostream>

using namespace std;

const int maxN = 15;
long long l = 0;
long long r = 0;
long long dp[maxN] = {0};
long long sum[maxN] = {0};
long long mi[maxN] = {0};
long long result2[maxN] = {0};
long long result3[maxN] = {0};
int a[maxN] = {0};
void ope(long long n, long long *result) {
    long long tmp = n;
    int idx = 0;
    while (tmp) {
        a[++idx] = tmp % 10;
        tmp /= 10;
    } 

    for (int i = idx; i >= 1; i--) {
        for (int j = 0; j < 10; j++) {
            result[j] += dp[i - 1] * a[i];
        } 
        for (int j = 0; j < a[i]; j++) {
            result[j] += mi[i - 1];
        }
        n -= mi[i - 1] * a[i];
        result[a[i]] += n + 1;
        result[0] -= mi[i - 1];
    }
}
int main() 
{
    cin >> l >> r;
    mi[0] = 1ll;

    for (int i = 1; i <= 13; i++) {
        dp[i] = dp[i - 1] * 10 + mi[i - 1];
        mi[i] = 10ll * mi[i - 1];
    }

    ope(r, result2);
    ope(l - 1, result3);

    for (int i = 0; i < 10; i++)  {
        cout << result2[i] - result3[i] << ' ';
    }

    cout << endl;
    return 0;
}