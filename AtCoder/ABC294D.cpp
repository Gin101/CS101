#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    set<int> se;

    int idx = 1;
    for (int i = 0; i < q; i++) {
        int op = 0;
        cin >> op;

        if (op == 1) {
            se.insert(idx++);
        } else if (op == 2) {
            int x = 0;
            cin >> x;

            se.erase(x);
        } else {
            cout << *se.begin() << endl;
        }
    }

    return 0;
}