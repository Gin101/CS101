#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100;
int d[maxN] = {0};

int main()
{
    int n = 0;
    int p = 0;
    int q = 0;
    cin >> n >> p >> q;

    int result = p - q;

    for (int i = 0; i < n; i++) {
        int d = 0;
        cin >> d;

        result = min(result, d);
    }

    cout << result + q << endl;

    return 0;
}