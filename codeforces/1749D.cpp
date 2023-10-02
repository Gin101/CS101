#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
int main()
{
    long long n = 0;
    long long m = 0;
    cin >> n >> m;

    long long result = 0;
    long long mul = 1;
    long long tmp = 1;
    long long num = 1;
    for (long long i = 1; i <= n; i++) {
        if (mul <= m && __gcd(mul, i) == 1) {
            mul *= i;
        }
        num = m % MOD * num % MOD;
        tmp = (m / mul) % MOD * tmp % MOD;
        result = (result + num - tmp + MOD) % MOD;
    }
	
    cout << result << endl;

	return 0;
}