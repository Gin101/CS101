#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long x = 0;
        cin >> x;

        long long result = 1;
        for (long long j = 2; j * j <= x; j++) {
            long long tmp = 0;
            long long tmp2 = 0;
            while (x % j == 0) {
                x /= j;
                tmp++;
            }

            if (j % 2 == 1) {
                result *= (tmp + 1);
            }
        }

        if (x != 1 && x % 2 == 1) {
            result *= 2;
        }
        cout << result << endl;
    }

    return 0;
}