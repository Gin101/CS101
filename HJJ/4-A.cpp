#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int maxN = 5e5;
char c[maxN] = {0};

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    sort(c, c + n, greater<int> ());

    int idx = 0;
    for (int i = 0; i < s.size(); i++) {
        if (c[idx] > s[i]) {
            s[i] = c[idx++];
        }
    }

    cout << s << endl;

    return 0;
}