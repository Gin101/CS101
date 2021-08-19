#include <iostream>

using namespace std;

const int maxN = 1e5;
int a[maxN] = {0};
int main()
{
    int n = 0;
    int t = 0;
    cin >> n >> t;

    long long sum = 0;
    int idx = 0;
    int result = 0;
    int result2 = 0;
	for(int i = 0; i < n; i++) {
        cin >> a[i];

		sum += a[i];
		while (sum > t) {
            sum -= a[idx++];
        }

		if (i - idx > result2 - result) {
            result = idx + 1;
            result2 = i + 1;
        } 
	}
	
    cout << result << ' ' << result2 << endl;

    return 0;
}