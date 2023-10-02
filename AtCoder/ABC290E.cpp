#include <iostream>
#include <map>

using namespace std;

const int maxN = 2e5 + 1;
long long a[maxN] = {0};
signed main()
{
    int n = 0;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long r = n / 2 + 1;
    long long l = r - 1 + n % 2;
    long long result = 0;
    map<int, int> mp;
    while (l) {
        result += l * ((a[l] != a[r]) + (l < r ? 2 * (r - l - 1) - mp[a[l]] - mp[a[r]] : 0));
        mp[a[l]] += (l < r);
        mp[a[r++]]++;
        l--;
    }
	
    cout << result << endl;

	return 0;
}