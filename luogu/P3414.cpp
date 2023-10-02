#include <iostream>

using namespace std;

const int MOD = 6662333;
long long Matrix(long long x, long long y) {
    if (y == 0) {
        return 1;
    }
    long long tmp = Matrix(x, y / 2);
    return (y & 1) ? (tmp * tmp % MOD) * (x % MOD) % MOD : (tmp * tmp) % MOD;
}

int main() 
{
    long long n = 0;
    cin >> n;

    cout << Matrix(2, n - 1) << endl;

    return 0;
}