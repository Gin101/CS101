#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    while (cin >> n) {
        int result = 0;
        vector<int> a(n);
        for (int &val : a) {
            cin >> val;
        }

        result = 2e9;
        for (int i = 2; i <= n; i++) {
            result = min(result, a[i] - a[i - 2]);
        }
    }

    return 0;
}