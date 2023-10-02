#include <iostream>

using namespace std;

int main()
{
    int k = 0;
    cin >> k;

    if (k >= 60) {
        cout << "22:";
        if (k - 60 >= 10) {
            cout << k - 60 << endl;
        } else {
            cout << '0' << k - 60 << endl;
        }
    } else {
        cout << "21:";
        if (k >= 10) {
            cout << k << endl;
        } else {
            cout << '0' << k << endl;
        }
    }

    return 0;
}