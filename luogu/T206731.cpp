#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n = 0;
        cin >> n;

        while (n % 2 == 0) {
            n /= 2;
        }

        if (n == 1 || n == 3) {
            cout << 0 << endl;
        } else {
            cout << 1 << endl;
        }
    }

    return 0;
}