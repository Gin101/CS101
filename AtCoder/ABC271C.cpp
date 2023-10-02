#include <iostream>

using namespace std;

const int maxN = 3e5;
bool flag[maxN] = {false};
int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a = 0;
        cin >> a;

        if (a <= n) {
            flag[a - 1] = true;
        }
    }

    for (int i = 0; i < n; i++) {
        if (flag[i] == false) {
            n--;
        }
    }
  
    cout << n << endl;

    return 0;
}