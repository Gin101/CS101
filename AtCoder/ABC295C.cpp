#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 5e5;
int a[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int result = 0;
    int pre = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[i - 1]) {
            result += (i - pre) / 2;
            pre = i;
        }
    }

    cout << result + (n - pre) / 2 << endl;

    return 0;
}