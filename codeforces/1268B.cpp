#include <iostream>

using namespace std;

long long result[2] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a = 0;
        cin >> a;

        result[i & 1] += a / 2;
        result[~i & 1] += (a + 1) / 2;
    }

    cout << (result[0] < result[1] ? result[0] : result[1]) << endl;

	return 0;
}