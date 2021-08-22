#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    bool flag = false;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != '0' || flag) {
            flag = true;
            cout << s[i];
        }
    }

    cout << endl;

    return 0;
}