#include <iostream>

using namespace std;

const int maxN = 1001;
int f[maxN] = {0};

int find(int num) {
    if (num != f[num]) {
        f[num] = find(f[num]);
    }
    return f[num];
}

int main()
{
    int n = 0;
    int m = 0;
    while (true) {
        int result = 0;
        cin >> n;
        if (n == 0) {
            break;
        } 
        cin >> m;
        for (int i = 0; i < n; i++) {
            f[i] = i;
        }

        for (int i = 0; i < m; i++) {
            int x = 0;
            int y = 0;
            cin >> x >> y;

            f[find(x - 1)] = y - 1;
        }

        for (int i = 0; i < n; i++) {
            if (find(i) == i) {
                result++;
            }
        }
        cout << result - 1 << endl;
    }

    return 0;
}