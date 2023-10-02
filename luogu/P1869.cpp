#include <iostream>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        int k = 0;
        cin >> n >> k;

        bool flag = false;
        while (n >= 2 && !flag) {
            if ((!(n & 1)) & (k & 1)) {
                flag = true;
            }
            n /= 2;
            k /= 2;
        }

        cout << (flag ? 0 : 1) << endl;
    }
	
	return 0;
}