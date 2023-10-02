#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 3e5;
const int maxK = 3e5;
int a[maxN] = {0};
int box[maxK] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if ((a[i] > 0 || a[i] == 0) && a[i] < k) {
            box[a[i]]++;
        }
    }

    for (int i = 0; i < k; i++) {
        if (box[i] == 0) {
            cout << i << endl;
            return 0;
        }
    }

    cout << k << endl;

    return 0;
}