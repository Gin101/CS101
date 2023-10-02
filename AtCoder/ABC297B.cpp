#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    int cnt = 0;
    int idx = -1;
    for (int i = 0; i < s.size(); i++) {
        if (idx == -1 && s[i] == 'B') {
            idx = i;
        } else if (i % 2 == idx % 2 && s[i] == 'B') {
            cout << "No" << endl;
            return 0;
        }
        if (s[i] == 'R') {
            cnt++;
        }
        if (cnt != 1 && s[i] == 'K') {
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}