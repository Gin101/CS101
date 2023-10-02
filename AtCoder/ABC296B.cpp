#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char c;
            cin >> c;
            if (c == '*') {
                cout << char(j + 97) << 8 - i << endl;
            }
        }
    }

    return 0;
}