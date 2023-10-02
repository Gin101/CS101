#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    long long x = 0;
    long long a = 0;
    long long d = 0;
    long long n = 0;
    cin >> x >> a >> d >> n;
  
    x -= a;

    if (d == 0 || d > 0 && x < 0 || d < 0 && x > 0) {
        cout << abs(x) << endl;
        return 0;
    }
    
    if((d > 0 && x >= (n - 1) * d) || (d < 0 && x < (n - 1) * d )) {
        cout << abs(x - ((n - 1) * d )) << endl;
        return 0;
    }

    cout << min(abs(x - (x / d) * d), abs(x - (x / d + 1) * d)) << endl;

    return 0;
}