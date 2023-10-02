#include <iostream>

using namespace std;

void ope(int num) {
    switch (num) {
        case 10: {
            cout << 'A';
            break;
        } case 11: {
            cout << 'B';
            break;
        } case 12: {
            cout << 'C';
            break;
        } case 13: {
            cout << 'D';
            break;
        } case 14: {
            cout << 'E';
            break;
        } case 15: {
            cout << 'F';
            break;
        } default: {
            cout << num;
        }
    }
    return;
}

int main()
{
    int n = 0;
    cin >> n;

    if (n == 0) {
        cout << "00" << endl;
        return 0;
    }
    int cnt = 0;
    while (n > 0) {
        if (n / 16 > 0) {
            ope(n / 16);
            n -= (n / 16) * 16;
            if (n == 0) {
                cout << 0;
            }
        } else {
            if (cnt == 0) {
                cout << 0;
                ope(n % 16);
            } else {
                ope(n % 16);
            }
            n -= n % 16;
        }
        cnt++;
    }

    cout << endl;

    return 0;
}