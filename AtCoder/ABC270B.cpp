#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int z = 0;
    cin >> x >> y >> z;

    if (x > 0) {
        if (0 < y && y <= x) {
            if (0 < z && z < y) {
                cout << x << endl;
            } else if (z < 0) {
                cout << x - z * 2 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << x << endl;
        }
    } else {
        if (x <= y && y < 0) {
            if (y < z && z < 0) {
                cout << -x << endl;
            } else if (z > 0) {
                cout << -x + z * 2 << endl;
            } else {
                cout << -1 << endl;
            }
        } else {
            cout << -x << endl;
        }
    }

    return 0;
}