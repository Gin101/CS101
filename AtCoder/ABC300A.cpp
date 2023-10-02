#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int a = 0;
    int b = 0;
    cin >> n >> a >> b;

    bool flag = true;
    for (int i = 0; i < n; i++) {
        int c = 0;
        cin >> c;

        if (flag && c == a + b) {
            flag = false;
            cout << i + 1 << endl;
        }
    }

    return 0;
}