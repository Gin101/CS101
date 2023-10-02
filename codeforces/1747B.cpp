#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x = 0;
        cin >> x;

        cout << x / 2 + x % 2 << endl;
        for (int j = 0; j < 3 * x / 2; j += 3) {
            cout << j + 1 << ' ' << 3 * x - j << endl;
        }
    }
	
    return 0;
}