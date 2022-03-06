#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e6 + 1;
const int maxM = 5e5 + 1;
const int MOD = 1e9 + 7;
long long box[maxN * 2] ={0};
long long c[maxM] = {0};
long long fac[maxM] = {0};
long long calc(long long l, long long r)  { 
    return (l + r) * (r - l + 1) % MOD * MOD % MOD; 
}
int main(void) 
{
    int m = 0;
    cin >> m;

    fac[0] = 1;
    for (int i = 1; i <= maxM; i++) {
        fac[i] = fac[i - 1] * i % MOD;
    }

    for (int i = 1; i <= m; i++) {
        cin >> c[i];
        box[maxN - c[i] + 1]++;
        box[maxN + c[i] + 1]--;
    }

    for (int i = 2; i <= maxN * 2; i++) {
        box[i] += box[i - 2];
    }

    long long result = 0;
    long long result2 = 0;
    for (int i = 0, x = 0; i <= maxN * 2; i++) {
        result2 *= fac[box[i]] % MOD;
        result = (result + (i - maxN) * calc(x + 1, x + box[i]) % MOD + MOD) % MOD;
        x += box[i];
    }

    cout << result << ' ' << result2 << endl;

    return 0;
}