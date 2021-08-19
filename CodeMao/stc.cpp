#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxN = 100001;
int b[maxN] = {0};//box
int main()
{
	int n = 0;
	int t = 0;
	int x = 0;
    cin >> n >> t >> x;

	int result = 0;
	int idx = 0;
    for(int i = 1; i <= n; i++) {
        int t2 = 0;
		cin >> t2;

        idx = 0;
        for(int j = t2 - 1; j >= t2 - t; j--) {
			if (b[j + 10000] != 0) {
				idx++;
			}
		}

        if (idx < x) {
			for (int j = t2 - 1; j >= t2 - t; j--) {
				if (b[j + 10000] == 0) {
                	b[j + 10000] = 1;
                	result++;
					idx++;
				}
                if (idx == x) {
					break;
				}
			}
		}
    }

	if (t < x) {
        cout << -1 << endl;
        return 0;
    }

    cout << result << endl;

    return 0;
}