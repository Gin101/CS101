#include <iostream>

using namespace std;

int main()
{
    long long a = 0;
    long long b = 0;
    cin >> a >> b;

    long long result = 0;
    while (a != 0 && b != 0) {
        if (a > b) {
            result += a / b;
            a -= (a / b) * b;
        } else {
            result += b / a;
            b -= (b / a) * a;
        }
    }

    cout << result - 1 << endl;

    return 0;
}