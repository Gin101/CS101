#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int first = 0;
    cin >> first;

    int result = first;
    bool flag = false;
    for (int i = 1; i < n; i++) {
        int x = 0;
        cin >> x;

        if (result < x) {
            flag = false;
            result = x;
        } else if (result == x) {
            flag = true;   
        }
    }

    if (first == result) {
        if (flag) {
            cout << 1 << endl;
        } else {
            cout << 0 << endl;
        }
    } else {
        cout << result - first + 1 << endl;
    }

    return 0;
}