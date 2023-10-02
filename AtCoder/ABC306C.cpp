#include <iostream>

using namespace std;

const int maxN = 1e5;
bool flag[maxN] = {false};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < 3 * n; i++) {
        int a = 0;
        cin >> a;

        if (flag[a - 1]) {
            cout << a << ' ';
            flag[a - 1] = false;
        } else {
            flag[a - 1] = true;
        }
    }
    cout << endl;

    return 0;
}