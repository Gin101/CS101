#include <iostream>

using namespace std;

int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            int a = 0;
            cin >> a;

            if (a == 0) {
                cout << '.';
            } else {
                cout << char(a + 64);
            }
        }
        cout << endl;
    }

    return 0;
}