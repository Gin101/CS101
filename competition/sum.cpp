#include <iostream>
#include <cmath>

using namespace std;

long long p = 0;
long long power(long long a, long long k, long long num, long long div, bool flag) {
    long long result = 1;
    while (k > 0) {
        if (!flag && (num * result % div) == 0) {
            result *= num;
            result /= div;
            result %= p;
            flag = true;
        }
        if (k & 1) {
            result = result * a;
            if (flag) {
                result %= p;
            }
        }
        a *= a;
        if (flag) {
            a %= p;
        }
        k /= 2;
    }
    return result;
}

int main()
{
    int t = 0;
    cin >> t;
    
    while (t--) {
        long long n = 0;
        long long a = 0;
        cin >> n >> a >> p;

        a %= p;

        if (a == 1) {
            cout << ((n * (n + 1)) / 2ll) % p << endl;
        } else {
            cout << power(a, n + 1ll, n * a - n + 1ll, (a - 1ll) * (a - 1ll), false) % p << endl;
        }
    }
    
    return 0;
}