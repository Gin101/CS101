#include <iostream>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    map<int, int> mp;
    for (int i = 1; i < n; i++) {
        for (int j = i; j < n; j += i) {
            mp[j]++;
        }
    }

    int result = 0;
    for (int i = 1; i <= n; i++) {
        result += mp[n - i] * mp[i];
    }

    cout << result << endl;
}