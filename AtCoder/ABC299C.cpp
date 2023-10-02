#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    int result = 0;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'o') {
            tmp++;
        } else {
            result = max(result, tmp);
            tmp = 0;
        }
    } 
    result = max(result, tmp);  

    if (result == n || result == 0) {
        cout << -1 << endl;
    } else {
        cout << result << endl;
    }

    return 0;
}