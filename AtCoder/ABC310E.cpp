#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    long long result = 0;
    long long cnt = 0;
    for (int i = 0; i < n; i++) {
        result += (cnt = i - (s[i] & 1) * (cnt - 1));
    }

    cout << result << endl;

    return 0;
}