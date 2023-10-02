#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int maxM = 2e5 + 1;
map<int, bool> flag[maxM];
int main()
{
    long long n = 0;
    long long m = 0;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++) {
        long long x = 0;
        cin >> x;

        for (long long j = max(1ll, (-x - 1) / i + 1); j <= m && x + i * j < m; j++) {
            flag[j][x + i * j] = true;
        }
    }
	
    for (int i = 1; i <= m; i++) {
        int result = 0;
        while (result < m && flag[i][result]) {
            result++;
        }
        cout << result << endl;
    }
	
    return 0;
}