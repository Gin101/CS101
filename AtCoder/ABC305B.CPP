#include <iostream>
#include <cmath>
#include <map>

using namespace std;

map<char, int> mp;
int main()
{
    mp['B'] = 3;
    mp['C'] = 4;
    mp['D'] = 8;
    mp['E'] = 9;
    mp['F'] = 14;
    mp['G'] = 23;
    char p;
    char q;
    cin >> p >> q;

    cout << abs(mp[q] - mp[p]) << endl;

    return 0;
}