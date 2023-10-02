#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if (n % 5 > 2) {
        cout << (n / 5 + 1) * 5 << endl;
    } else {
        cout << (n / 5) * 5 << endl;
    }

    return 0;
}