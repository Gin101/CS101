#include <iostream>
#include <bitset>

using namespace std;

const int maxN = 101;
int p[maxN] = {0};
int c[maxN] = {0};
bitset<maxN> f[maxN];

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> p[i] >> c[i];
        for (int j = 1; j <= c[i]; j++) {
            int t = 0;
            cin >> t;

            f[i][t] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((f[i] | f[j]) == f[i] && (p[i] < p[j]) || (p[i] == p[j] && c[i] > c[j])) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}