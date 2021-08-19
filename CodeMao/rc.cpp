#include <iostream>

using namespace std;

int main()
{
    int x = 0;
    int y = 0;
    int k = 0;
    cin >> x >> y >> k;

    int result = 0;
    for (int i = 0; i < k; i++) {
        if (x < 0) {
            x = 0;
        }
        if (y < 0) {
            y = 0;
        }

        if (x == y) {
            cout << result << endl;
            return 0;
        }

        int a = 0;
        int x2 = 0;
        int b = 0;
        int y2 = 0;
        cin >> a >> x2 >> b >> y2;

        x += (a * x2);
        y += (b * y2);

        result++;
    }

    if (x == y) {
        cout << result << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}