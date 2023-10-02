#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int main()
{
    long long n = 0;
    long long m = 0;
    cin >> n >> m;

    long long cnt = 1;
    long long result = LONG_MAX;
    while (cnt <= n) {
        long long tmp = (m - 1) / cnt;
        long long r = tmp == 0 ? n : min((m - 1) / tmp, n);

        if (tmp + 1 <= n) {
            result = min(result, (tmp + 1) * cnt);
        }
        cnt = r + 1;
    }

    if (result == LONG_MAX) {
        result = -1;
    }

    cout << result << endl;
	
    return 0;
}
