#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int n = 0;
    string s;
    cin >> n >> s;

    int x = 0;
    int y = 0;
    
    bool flag = false;
    map<pair<int, int>, int> mp;
    mp[make_pair(0, 0)]++;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case 'R' : {
                x++;
                break;
            } case 'L' : {
                x--;
                break;
            } case 'U' : {
                y++;
                break;
            } case 'D' : {
                y--;
            }
        }

        mp[make_pair(x, y)]++;
        if (mp[make_pair(x, y)] > 1) {
            flag = true;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}