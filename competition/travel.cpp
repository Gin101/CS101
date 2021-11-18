#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    freopen("traval.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int n = 0;
    int m = 0;
    int a = 0;
    int b = 0;
    cin >> n >> m >> a >> b;

    int result = 0;

    while (n > 0) {
        if (a * m <= b) {
            n -= m;
            result += a * m;
        } else {
            if (n < m) {
                if (a * n <= b) {
                    result += a * n;
                    n = 0;
                } else {
                    n = 0;
                    result += b;
                }
            } else {
                n -= m;
                result += b;
            }
        }
    }

    cout << result << endl;
    

    return 0;
}