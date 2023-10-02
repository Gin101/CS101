#include <iostream>
#include <algorithm>

using namespace std;

const int maxA = 1001;
long long a[maxA][maxA] = {{0}};
int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> a[i][i];
    }
    for (int i = n - 1; i >= 1; i--) {
        for (int j = i + 1; j <= n; j++) {
            a[i][j] = __gcd(a[i][i], a[i + 1][j]);
        }
    }
    for (int i = 1; i <= m; i++) {
        int p = 0;
        int q = 0;
        cin >> p >> q;

        cout << a[p][q] << endl;
    }
    
    return 0;
}