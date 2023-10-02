#include <iostream>

using namespace std;

const int maxM = 2e5;
bool flag[maxM] = {false};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        if (!flag[a - 1]) {
            flag[a - 1] = true;
            cout << a << ' ';
        }
    }

    cout << endl;

    return 0;
}