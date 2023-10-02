#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
int a[maxN] = {0};

int main()
{
    int n = 0;
    int x = 0;
    cin >> n >> x;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    int idx = 0;
    int idx2 = 0;
    while (idx < n && idx2 < n) {
        if (a[idx2] - a[idx] < x) {
            idx2++;
        } else if (a[idx2] - a[idx] > x) {
            idx++;
        } else {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}