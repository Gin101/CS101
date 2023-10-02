#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    freopen("r.in", "r", stdin);
    freopen("r.out", "w", stdout);

    long long t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long a = 0;
        long long b = 0;
        cin >> a >> b;

        long long result = 0;
        while (b) {
            if (a > b) {
                swap(a, b);
            }
            result += b / a;
            b %= a;
        }

        cout << result << endl;
    }

    return 0;
}