#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
int a[maxN] = {0};

int main()
{
	int t = 0;
    cin >> t;
	
    for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;

		for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

		sort(a, a + n);
        int sum = 0;
        int result = 0;
		for (int i = 0; i < n; i++) {
			a[i] -= sum;
            sum += a[i];
			result = max(a[i], result);
		}
		
        cout << result << endl;
	}

	return 0;
}