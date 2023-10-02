#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

set<string> se;
int main()
{
    int n = 0;
    cin >> n;

    int result = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (!se.count(s)) {
            result++;
        }
        se.insert(s);
        reverse(s.begin(), s.end());
        se.insert(s);
    }

    cout << result << endl;

    return 0;
}