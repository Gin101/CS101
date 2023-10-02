#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 5000;
long long a[maxN] = {0};
int main() 
{
    int n = 0;
    long long k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    long long sum = 0;
    long long result = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (sum + a[i] >= k) {
            result =0; 
        } else {
            result++;
            sum += a[i];
        }
    }
	
    cout << result << endl;

	return 0;
}