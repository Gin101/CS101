#include <iostream>
#include <limits.h>
#include <algorithm>

using namespace std;

const int maxN = 2e5 + 1;
long long num[maxN * 2] = {0};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int p = 0;
        cin >> p;
        
        p = (p + n - i) % n;
        num[p]++;
        num[p + n]++;
        num[p + n / 2]--;
        num[p + (n + 1) / 2]--;

    }
	
    for (int i = 1; i <= 2 * n; i++) {
        num[i] += num[i - 1];
    }
    for (int i = 1; i <= 2 * n; i++) {
        num[i] += num[i - 1];
    }

    long long result = LONG_MAX;
    for (int i = 0; i < n; i++) {
        result = min(result, num[i] + num[i + n]);
    }
    cout << result << endl;

    return 0;
} 