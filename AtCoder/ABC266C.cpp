#include <iostream>

using namespace std;

int x[4] = {0};
int y[4] = {0};
bool check(int idx, int idx2, int idx3) {
    return (x[idx2] - x[idx]) * (y[idx3] - y[idx]) - (y[idx2] - y[idx]) * (x[idx3] - x[idx]) > 0;
}
int main()
{
    for (int i = 0; i < 4; i++) {
        cin >> x[i] >> y[i];
    }

    cout << (check(0, 1, 2) && check(0, 2, 3) && check(1, 2, 3) && check(1, 3, 0) ? "Yes" : "No") << endl;

    return 0;
}
