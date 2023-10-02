#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    if (n == 3) {
        cout << 2 << ' ' << 5 << ' ' << 63 << endl;  
    } else {
        int num = n % 3 ? n - 2 : n - 4;
        if (num > 15000) {
            num = n % 2 ? 14999 : 15000;
        }
        for (int i = 1; i <= num; i++) {
            cout << i * 2 << ' ';
        }
        for (int i = 0; i < n - num; i++) {
            cout << i * 6 + 3 << ' ';
        }
        cout << endl;
    }

    return 0;
}