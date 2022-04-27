#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n = 0;
        cin >> n;

        int result = 0;
        bool flag = true;
        while (n != 0) {
            if (result == 9) {
                cout << 9 << endl;
                flag = false;
                break;
            }

            result = max(result, n % 10);
            n /= 10;
        }

        if (flag) {
            cout << result << endl;
        }
    }
    
    return 0;
}