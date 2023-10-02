#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        cout << char(s[i] - 32);
    }
    cout << endl;

    return 0;
}