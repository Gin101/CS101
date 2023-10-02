#include <iostream>

using namespace std;

int main()
{
    unsigned long long result = 0;
    for (int i = 0; i < 64; i++) {
        unsigned long long a = 0;
        cin >> a;

        for (int j = 0; j < i; j++) {
            a *= 2ll;
        }
        result += a;
    }
    cout << result << endl;

    return 0;
}