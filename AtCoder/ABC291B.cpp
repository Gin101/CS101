#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 500;
double x[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < 5 * n; i++) {
        cin >> x[i];
    }

    sort(x, x + (5 * n));

    double result = 0;
    for (int i = n; i < 4 * n; i++) {
        result += x[i];
    }

    cout << result / (3 * n) << endl;

    return 0;
}