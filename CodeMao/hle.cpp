#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
    int n = 0;
    int t = 0;
    cin >> n >> t;

    vector<int> v;

    int sum = 0;
    int c = 0;
    for (int i = 0; i < n; i++) {
        cin >> c;

        sum += c;
        v.push_back(c);
    }

    if (sum < t) {
        cout << "Angry" << endl;
    } else {
        sum = n;
        c = 0;

        int l = 0;
        int r = 0;
        while (true) {
            while(r < n && c < t) {
                c += v[r++];
            }

            if (c < t) {
                break;
            }
            sum = min(r - l, sum);
            c -= v[l++];
        }
        cout << sum << endl;
    }

    return 0;
}