#include <iostream>

using namespace std;

const int maxA = 350;
bool flag[maxA] = {false};
int a[3] = {0};
int main() 
{
    int n = 0;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        result ^= a[i];
    }

    int idx = 0;
    if (n == 2) {
        if (a[1] < a[0]) {
            a[1] ^= a[0];
            a[0] ^= a[1];
            a[1] ^= a[0];
        }

        for (int i = 1; i < a[0]; i++) {
            if (!flag[i]) {
                idx++;
                flag[i + idx] = true;
            }
        }

        if (a[0]) {
            idx++;
            result = !(!flag[a[0]] && a[0] + idx == a[1]);
        }
    }

    if (result) {
        cout << "BitLGM" << endl;
    } else {
        cout << "BitAryo" << endl;
    }

    return 0;
}