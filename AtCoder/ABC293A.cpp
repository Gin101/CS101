#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < s.size() / 2; i++) {
        cout << s[2 * i + 1] << s[2 * i];
    }

    if (s.size() % 2 == 1) {
        cout << s[s.size() - 1];
    }
    cout << endl;

    return 0;
}