#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int l = 1;
    int r = n;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        cout << "? " << mid << endl;
        int num = 0;
        cin >> num;

        if (num == 0) {
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << "! " << l << endl;

    return 0;
}