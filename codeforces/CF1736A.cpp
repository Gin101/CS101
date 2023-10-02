#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
int a[maxN] = {0};
int b[maxN] = {0};
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int cnt = 0;
        a[0] = 0;
        b[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            a[0] += a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
            b[0] += b[i];
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] != b[i]) {
                cnt++;
            }
        }

        cout << min(cnt, abs(a[0] - b[0]) + 1) << endl;
    }
	
	return 0;
}