#include <iostream>

using namespace std;

const int maxM = 101;
int d[maxM] = {0};
int s[maxM] = {0};
int main()
{
    int m = 0;
    cin >> m;

    for (int i = 1; i <= m; i++) {
        cin >> d[i];
        s[i] = s[i - 1] + d[i];
    }

    int mid = s[m] / 2;
    while (s[m] > mid) {
        m--;
    }

    cout << m + 1 << ' ' << mid - s[m] + 1 << endl;

	return 0;
}