#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        for (int j = 0; j < n; j++) {
            cout << ((j - i + n) % n * i + x) % n << ' ';
        }
        cout << endl;
    }

    cout << endl;
}
