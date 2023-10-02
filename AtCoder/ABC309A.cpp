#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    cin >> a >> b;

    int numa = min(a, b);
    int numb = max(a, b);
    switch (numa) {
        case 1: {
            if (numb == 2) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        } case 2: {
            if (numb == 3) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        } case 4: {
            if (numb == 5) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        } case 5: {
            if (numb == 6) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        } case 7: {
            if (numb == 8) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        } case 8: {
            if (numb == 9) {
                cout << "Yes" << endl;
                return 0;
            }
            break;
        }
    }

    cout << "No" << endl;

    return 0;
}