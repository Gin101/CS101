#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n = 0;
        cin >> n;

        long long result = 0;
        for (int j = 0; j < n; j++) {
            long long a = 0;
            cin >> a;

            result += a;
        }

        long long tmp = 0;
        for (int j = 0; j < n; j++) {
            long long b = 0;
            cin >> b;

            result += b;
            tmp = max(tmp, b);
        }

        cout << result - tmp << endl;
    }

    return 0;
}