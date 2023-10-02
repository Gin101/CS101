#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    int l = 0;
    int r = 0;
    cin >> n >> l >> r;

    int result = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        a %= l + r;
        result ^= a / l;
    }
    if (result) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    return 0;
}