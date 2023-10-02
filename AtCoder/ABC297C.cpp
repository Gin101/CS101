#include <iostream>
#include <string>

using namespace std;

int main()
{
    int h = 0;
    int w = 0;
    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        string s;
        cin >> s;

        int idx = 0;
        while (idx < w - 1) {
            if (s[idx] == 'T' && s[idx + 1] == 'T') {
                s[idx] = 'P';
                s[idx + 1] = 'C';
                idx += 2;
            } else {
                idx++;
            }
        }
        cout << s << endl;
    }

    return 0;
}