#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;

        string result;
        for (int j = 0; j < 100; j++) {
            result += "Yes";
        }
        if (result.find(s) != -1) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}