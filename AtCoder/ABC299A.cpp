#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
        if (flag && s[i] == '|') {
            flag = false;
        } else if (!flag && s[i] == '|') {
            cout << "out" << endl;
            return 0;
        }
        if (s[i] == '*' && !flag) {
            cout << "in" << endl;
            return 0;
        }
    }

    cout << "out" << endl;

    return 0;
}