#include <iostream>
#include <string> 

using namespace std;

bool pre(string x, string y) {
    if (x.substr(0, y.size()) == y) {
        return true;
    }
    return false;
}
bool suf(string x, string y) {
    if (x.substr(x.size() - y.size(), y.size()) == y) {
        return true;
    }
    return false;
}

int main()
{
    int n = 0;
    int m = 0;
    string s;
    string t;
    cin >> n >> m >> s >> t;

    if (pre(t, s) && suf(t, s)) {
        cout << 0 << endl;
    } else if (pre(t, s)) {
        cout << 1 << endl;
    } else if (suf(t, s)) {
        cout << 2 << endl;
    } else {
        cout << 3 << endl;
    }

    return 0;
}