#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

const int maxN = 1e5;
int n = 0;
int k = 0;
int x[maxN] = {0};
bool check(int num) {
    int cnt = 0;
    int tmp = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (tmp + num < x[i]) {
            cnt++;
            tmp = x[i] + num;
        }
        if (cnt > k) {
            return false;
        }
    }

	return true;
}
int main()
{   
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x + n);
    int l = 1; 
    int r = x[n - 1];
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
        } else {
            l = mid + 1;
        }
	}

    cout << l << endl;

	return 0;
}