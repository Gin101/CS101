#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 6e5 + 2;
int a[maxN] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        if (y > a[x]) {
            a[x + n] = a[x] / 2;
            a[x] = y;
        } else {
            a[x + n] = max(a[x + n], y / 2);
        }
    }

    sort(a + 1, a + 2 * n + 1);

    cout << a[2 * n] + a[2 * n - 1] << endl;

	return 0;
}
