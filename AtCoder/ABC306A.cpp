#include <iostream>

using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        char a;
        cin >> a;
        cout << a << a;
    }
    cout << endl;

    return 0;
}