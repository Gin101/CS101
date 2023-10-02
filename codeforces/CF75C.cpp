#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

set<int> se;

int main()
{
    int a = 0;
    int b = 0;
    int q = 0;
    cin >> a >> b >> q;

    int num = __gcd(a, b);
    for (int i = 1; i * i <= num; i++) {
        if (num % i == 0) {
            se.insert(i);
            if (i * i != num) {
                se.insert(num / i);
            }
        }  
    }

    for (int i = 0; i < q; i++) {
        int l = 0;
        int r = 0;
        cin >> l >> r;

        int tmp = *--se.upper_bound(r);
        cout << (l > tmp ? -1 : tmp) << endl;
    }

    return 0;
}