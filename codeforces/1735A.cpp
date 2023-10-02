#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        cout << ((n - (n % 3)) / 3) - 2 << endl;
    }

    return 0;
}