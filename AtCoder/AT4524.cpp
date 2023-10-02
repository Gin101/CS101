#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int resultA = 0;
    int resultB = 0;
    int resultC = 0;
    for (int i = 0; i < n; i++) {
        int a = 0;
        int b = 0;
        int c = 0;
        cin >> a >> b >> c;

        a += max(resultB, resultC);
        b += max(resultA, resultC);
        c += max(resultA, resultB);
        resultA = a;
        resultB = b;
        resultC = c;
    }

    cout << max(max(resultA, resultB), resultC) << endl;;

    return 0;
}
