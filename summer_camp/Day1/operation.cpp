#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

const long long maxNK = 2e5;
const long long MOD = 998244353;
long long a[maxNK] = {0};
long long b[maxNK] = {0};
long long idx[maxNK] = {0};
bool flag[maxNK] = {0};

int main()
{
    freopen("operation.in", "r", stdin);
    freopen("operation.out", "w", stdout);

    long long t = 0;
    cin >> t;

    for (long long i = 0; i < t; i++) {
        long long n = 0;
        long long k = 0;
        cin >> n >> k;

        memset(idx, 0, sizeof(idx));
        memset(flag, false, sizeof(flag));

        for (long long j = 0; j < n; j++) {
            cin >> a[j];
            idx[a[j] - 1] = j;
        }

        for (long long j = 0; j < k; j++) {
            cin >> b[j];
            flag[b[j] - 1] = true;
        }

        long long result = 1;
        bool zero = false;
        for (long long j = 0; j < k; j++) {
            if (b[j] == a[0]) {
                if (!flag[a[1] - 1]) {
                    flag[b[j] - 1] = false;
                } else {
                    cout << 0 << endl;
                    zero = true;
                    break;
                }
            } else if (b[j] == a[n - 1]) {
                if (!flag[a[n - 2] - 1]) {
                    flag[b[j] - 1] = false;
                } else {
                    cout << 0 << endl;
                    zero = true;
                    break;
                }
            } else {
                flag[b[j] - 1] = false;
                if (!flag[a[idx[b[j] - 1] - 1] - 1] && !flag[a[idx[b[j] - 1] + 1] - 1]) {
                    result *= 2;
                    result %= MOD;
                } else if (flag[a[idx[b[j] - 1] - 1] - 1] && flag[a[idx[b[j] - 1] + 1] - 1]) {
                    cout << 0 << endl;
                    zero = true;
                    break;
                }
            }
        }

        if (!zero) {
            cout << result << endl;
        }
    }

    return 0;
}