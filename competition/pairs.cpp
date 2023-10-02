#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

const int maxN = 2e5;
int a[maxN] = {0};

int main()
{
    freopen("pairs.in", "r", stdin);
    freopen("pairs.out", "w", stdout);

    int n = 0;
    cin >> n;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int tmp = 2;
    while (tmp < sum) {
        tmp *= 2;
    }

    int result = 0;
	for (int i = tmp; i >= 2; i /= 2) {
		int idx = n - 1;
		for (int j = 0; j < n; j++) {
            if (a[j] > 0 && a[j] < i) {
                while ((a[idx] == 0 || a[j] + a[idx] > i) && idx > j) {
                    idx--;
                }
				if (idx > j && a[j] + a[idx] == i){
					a[j] = 0;
                    a[idx] = 0;
                    result++;
				}
            }
        }
	}
	
    cout << result << endl;

    return 0;
}