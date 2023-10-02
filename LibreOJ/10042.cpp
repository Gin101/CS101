#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main()
{
    int n = 0;
    cin >> n;

    int pre = 0;
    int result = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        cin >> x;
        
        if (mp.count(x) && mp[x] >= pre) {
            result = max(result, i - pre);
            pre = mp[x] + 1;
        }

        mp[x] = i;
    }

    cout << max(result, n - pre) << endl;

    return 0;
}