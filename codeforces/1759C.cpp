#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int l = 0;
        int r = 0;
        int x = 0;
        int a = 0;
        int b = 0;
        cin >> l >> r >> x >> a >> b;

        if (a == b) {
            cout << 0 << endl;
        } else if (abs(a - b) >= x) {
            cout << 1 << endl;
        } else if (a - l >= x && b - l >= x || r- a >= x && r - b >= x) {
            cout << 2 << endl;
        } else if (a - l >= x && r - l >= x && r - b >= x || r - a >= x && r - l >= x && b - l >= x) {
            cout << 3 << endl;
        } else {
            cout << -1 << endl;
        }
    }
	
    return 0;
}