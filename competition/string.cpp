#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int result = 2;
        for (int j = 1; j < s.size(); j++) {
            if (s[j] != s[j - 1]) {
                result += 2;
            }
        }

        cout << result << endl;
    }

    return 0;
}