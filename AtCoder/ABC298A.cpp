#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    int cnt = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;

        if (c == 'o') {
            cnt++;
        } else if (c == 'x') {
            cnt2++;
        }
    }

    if (cnt >= 1 && cnt2 == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}