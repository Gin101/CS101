#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    for (int i = 2; i < n; i++) {
        if (s[i - 2] == 'A' && s[i - 1] == 'B' && s[i] == 'C') {
            cout << i - 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}