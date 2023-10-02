#include <iostream>

using namespace std;

#define int long long

signed main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int m = 0;
        cin >> n >> m;

        int tmp = n;
        int cnt = 0;
        int cnt2 = 0;
        while (n % 2 == 0) {
            n /= 2;
            cnt++;
        }
        while (n % 5 == 0) {
            n /= 5;
            cnt2++;
        }

        int result = 1;
        while (true) {
            if (cnt < cnt2) {
                n = 2;
                cnt++;
            } else if (cnt > cnt2) {
                n = 5;
                cnt2++;
            } else {
                n = 10;
                cnt++;
                cnt2++;
            }
            if (result * n > m) {
                break;
            }
            result *= n;
        }

        cout << m / result * result * tmp << ' ';
    }

    return 0;
}