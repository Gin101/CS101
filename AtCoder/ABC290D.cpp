#include <iostream>
#include <algorithm>

using namespace std;

int main() 
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n = 0;
        long long d = 0;
        long long k = 0;
        cin >> n >> d >> k;

        cout << (k - 1) / (n / __gcd(n, d)) + (k - 1) * d % n << endl;
    }

    return 0;
}