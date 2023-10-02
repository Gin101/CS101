#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    int p = 0;
    cin >> n >> m >> p;

    int result = 0;
    for (int i = m; i <= n; i += p) {
        result++;
    }
    cout << result << endl;

    return 0;
}