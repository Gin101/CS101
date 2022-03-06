#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int a = 0;
        int d = 0;
        cin >> n >> a >> d;

        int result = 0;
        while (d % 2 == 0 && n >= 2) {
            int tmp = n % 2;
            result += n / 2;
            n /= 2;
            n += tmp;
        }

        cout << result << endl;
    }

    return 0;
}