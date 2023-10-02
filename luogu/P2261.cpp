#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() 
{
    long long n = 0;
    long long k = 0;
    cin >> n >> k;

    long long result = n * k;
    for (long long l = 1, r; l <= n; l = r + 1) {
        if (k / l != 0) {
            r = min(k / (k / l), n);
        } else {
            r = n;
        }
        result -= (k / l) * (r - l + 1) * (l + r) / 2;
    }
    cout << result << endl;

    return 0;
}