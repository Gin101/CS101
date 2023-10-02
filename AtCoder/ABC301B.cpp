#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int pre = 0;
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;

        if (pre != 0) {
            if (abs(num - pre) != 1) {
                if (num > pre) {
                    for (int j = pre + 1; j < num; j++) {
                        cout << j << ' ';
                    }
                } else {
                    for (int j = pre - 1; j > num; j--) {
                        cout << j << ' ';
                    }
                }
            }
        }
        cout << num << ' ';
        pre = num;
    }

    cout << endl;

    return 0;
}