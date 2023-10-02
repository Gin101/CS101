#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int h = 0;
    int x = 0;
    cin >> n >> h >> x;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        int p = 0;
        cin >> p;

        if (!flag && h + p >= x) {
            cout << i + 1 << endl;
            flag = true;
        }
    }

    return 0;
}