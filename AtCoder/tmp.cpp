#include <iostream>

#include <algorithm>

using namespace std;

int a[20000] = {0};

bool cmp(int x, int y) {
    return x == 1;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n, cmp);

    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    return 0;
}