#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s == "and" || s == "not" || s == "that" || s == "the" || s == "you") {
            flag = true;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}