#include <iostream>
#include <string>

using namespace std;

bool flag[3] = {false};

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            flag[0] = true;
        } else if (s[i] == 'B') {
            flag[1] = true;
        } else {
            flag[2] = true;
        }
        if (flag[0] && flag[1] && flag[2]) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}