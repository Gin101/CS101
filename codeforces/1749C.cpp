#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 101;
int a[maxN] = {0};
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        int result = (n + 1) / 2;
        while (result) {
            bool flag = true;
            for (int i = 1; i <= result && flag; i++) {
                if (a[i + result - 1] > i) {
                    flag = false;
                }
            }
            if (flag) {
                break;
            }
            result--;
        }

        cout << result << endl;
    }
    
	return 0;
}

