#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    string s;
    cin >> s;

    long long sum = 0;
    for (int i = 0; i < q; i++) {
        int t = 0;
        int x = 0;
        cin >> t >> x;

        if (t == 1) {
            sum += x;
        } else {
            int tmp = x - sum % n - 1;
            if (tmp >= 0) {
                cout << s[tmp] << endl;
            } else {
                cout << s[n + tmp] << endl;
            }
        }
    }

    return 0;
}