#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int d = 0;
    cin >> n >> d;

    int t = 0;
    cin >> t;

    int pre = t;
    bool flag = true;
    for (int i = 1; i < n; i++) {
        cin >> t;

        if (flag && t - pre <= d) {
            cout << t << endl;
            flag = false;
        }
        pre = t;
    }

    if (flag) {
        cout << -1 << endl;
    }

    return 0;
}