#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    int t = 0;
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            t++;
        } else {
            a++;
        }
    }

    if (t > a) {
        cout << 'T' << endl;
    } else if (t < a) {
        cout << 'A' << endl;
    } else {
        if (s[n - 1] == 'T') {
            cout << 'A' << endl;
        } else {
            cout << 'T' << endl;
        }
    }

    return 0;
}