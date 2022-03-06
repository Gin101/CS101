#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

vector<int> num;
vector<int>::iterator it;

int main()
{
    int q = 0;
    cin >> q;

    num.insert(it, INT_MIN);
    num.push_back(INT_MAX);
    for (int i = 0; i < q; i++) {
        int op = 0;
        int x = 0;
        cin >> op >> x;

        switch (op) {
            case 1: {
                it = lower_bound(num.begin(), num.end(), x);
                cout << it - num.begin() << endl;
                break;
            } case 2: {
                cout << num[x] << endl;
                break;
            } case 3: {
                it = lower_bound(num.begin(), num.end(), x);
                cout << num[it - num.begin() - 1] << endl;
                break;
            } case 4: {
                it = upper_bound(num.begin(), num.end(), x);
                cout << num[it - num.begin()] << endl;;
                break;
            } case 5: {
                num.insert(upper_bound(num.begin(), num.end(), x), x);
            }
        }
    }

    return 0;
}