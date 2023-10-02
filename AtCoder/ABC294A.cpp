#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        if (a % 2 == 0) {
            cout << a << ' ';
        }
    }

    cout << endl;

    return 0;
}