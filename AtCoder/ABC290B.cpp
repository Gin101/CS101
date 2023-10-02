#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt < m && s[i] == 'o') {
            cout << 'o';
            cnt++;
        } else {
            cout << 'x';
        }
    }

    cout << endl;

    return 0;
}