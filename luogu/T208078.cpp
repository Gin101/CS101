#include <iostream>
#include <cmath>

using namespace std;

const int maxN = 1e5;
long long a[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n; 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 1; i < n; i++) {
        a[i] = abs(a[i]);
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        result += a[i];
    }

    cout << result << endl;

    return 0;
}