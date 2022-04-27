#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int l = 0;
    int r = 0;
    cin >> n >> l >> r;

    int result = 0;
    for (int i = l; i <= r; i++) {
        if (i % n == (n - 1)) {
            cout << n - 1 << endl;
            return 0;
        }

        result = max(result, i % n);
    }

    cout << result << endl;

}