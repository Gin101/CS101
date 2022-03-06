#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 1001;
long long result[maxN] = {0};
int main()
{
    int n = 0;
    int m = 0;
    int c = 0;
    int d = 0;
    cin >> n >> m >> c >> d;

    for (int i = c; i <= n; i++) {
        result[i] = result[i - c] + d;
    }

    for (int i = 0; i < m; i++) {
        int a = 0;
        int b = 0;
        cin >> a >> b >> c >> d;
        for (int i = 0; i < a / b; i++) {
            for (int j = n; j >= c; j--) {
                result[j] = max(result[j - c] + d, result[j]);
            }
        }
    }

    cout << result[n] << endl;

    return 0;
}
