#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<int> a(n);
    for (auto && v : a) {
        cin >> v;
        v--;
    }
    
    for (int i = 0; i < 18; i++) {
        vector<int> tmp(n);
        for (int j = 0; j < n; j++) {
            tmp[j] = a[a[j]];
        }
        swap(a, tmp);
    }

    cout << set<int>(a.begin(), a.end()).size() << endl;

    return 0;
}