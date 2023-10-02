#include <iostream>

using namespace std;

const int maxN = 100;
int a[maxN] = {0};

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        int b = 0;
        cin >> b;
        result += a[b - 1];
    }

    cout << result << endl;

    return 0;
}