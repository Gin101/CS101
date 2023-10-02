#include <iostream>

using namespace std;

const int maxN = 2e5;
int a[maxN] = {0};
bool flag[maxN] = {false};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            flag[a[i] - 1] = true;
        }
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            result++;
        }
    }

    cout << result << endl;
    for (int i = 0; i < n; i++) {
        if (!flag[i]) {
            cout << i + 1 << ' ' ;
        }
    }

    cout << endl;

    return 0;
}