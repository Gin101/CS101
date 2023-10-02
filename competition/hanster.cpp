#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1e5;
int a[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int cnt = 0;
    int result = 0;
    for (int i = n - 1; i >= 0; i--) {
        cnt++;
        if (cnt == 3) {
            result += a[i + 2] - a[i];
            cnt = 0;
        }
    }

    if (cnt != 0) {
        result += a[cnt - 1] - a[0];
    }

    cout << result << endl;

    return 0;
}