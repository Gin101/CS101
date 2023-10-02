#include <iostream>

using namespace std;

int main()
{
    int h = 0;
    int m = 0;
    cin >> h >> m;

    if (0 <= h && h <= 5) {
        cout << h << ' ' << m << endl;
    } else if (6 <= h && h <= 9) {
        cout << 10 << ' ' << 0 << endl;
    } else if (10 <= h && h <= 15) {
        cout << h << ' ' << m << endl;
    } else if (16 <= h && h <= 19) {
        cout << 20 << ' ' << 0 << endl;
    } else if ((40 <= m && m <= 49) || (m == 4)) {
        if (20 <= h && h <= 22) {
            cout << h + 1 << ' ' << 0 << endl;
        } else {
            cout << 0 << ' ' << 0 << endl;
        }
    } else  {
        if (0 <= m && m <= 39) {
            cout << h << ' ' << m << endl;
        } else {
            if (20 <= h && h <= 22) {
                cout << h + 1 << ' ' << 0 << endl;
            } else {
                cout << 0 << ' ' << 0 << endl;
            }
        }
    }

    return 0;
}