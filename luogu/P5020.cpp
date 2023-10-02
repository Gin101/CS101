#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int maxN = 1001;
int a[maxN] = {0};
int flag[25001] = {0};
int main() 
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        for (int j = 1; j <= n; j++) {
            cin >> a[j];
        }

        sort(a + 1, a + n + 1);

        memset(flag, false, sizeof(flag));
        flag[0] = true;
        int result = 0;
        for (int j = 1; j <= n; j++) {
            result += !flag[a[j]];
            for (int k = a[j]; k <= a[n]; k++) {
                flag[k] |= flag[k - a[j]];
            }
        }

        cout << result << endl;
    }
    
    return 0;
}