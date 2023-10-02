#include <iostream>

using namespace std;

const long long MOD = 1e5 + 3;
long long Matrix(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
    long long tmp = Matrix(x, y / 2);
    return (y & 1) ? (tmp * tmp % MOD) * (x % MOD) % MOD : (tmp * tmp) % MOD;
}

int main()
{
    long long m = 0;
    long long n = 0;
    cin >> m >> n;

    long long result = Matrix(m, n) - (m % MOD) * Matrix(m - 1, n - 1) % MOD;
    while (result < 0) {
        result += MOD;
    }
    result %= MOD;

    cout << result << endl;

	return 0;
}