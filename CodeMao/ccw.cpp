#include <iostream>

using namespace std;

const int maxN = 1000001;
int f[maxN] = {0};
int a[maxN] = {0};

int lower_bound(int num, int r) { //I don’t know how to write lower_bound in C++'s STL, so I wrote one by myself
	int l = 1;
    int result = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (f[mid] > num) {
			result = mid;
			r = mid - 1;
		} else {
            l = mid + 1;
        }
	}

	return result;
}

int main()
{
	int n = 0;
    int m = 0;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

    int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (a[i] >= m) {
			if (a[i] >= f[idx]) {
				f[++idx] = a[i];
			} else {
                int tmp = lower_bound(a[i], idx);
				f[tmp] = a[i];
			}
		}
		if (a[i] * 2 >= m) {
			if (a[i] * 2 >= f[idx] && (a[i] < f[idx] || i == 1)) {
				f[++idx] = a[i] * 2;
			} else {
                int tmp2 = lower_bound(a[i] * 2, idx);
				f[tmp2] = a[i] * 2;
			}
		}
	}

	cout << idx << endl;

	return 0;
}