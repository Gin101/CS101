#include <iostream>
#include <set>

using namespace std;

set<int> s;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        s.insert(a);
    }

    int i = *s.begin();
    while(s.count(i)) {
        i++;
    }

    cout << i << endl;

    return 0;
}