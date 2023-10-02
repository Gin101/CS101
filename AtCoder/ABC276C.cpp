#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100;
int p[maxN] = {0};
int idx[maxN] = {0};

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    for (int i = n - 2; i >= 0; i--) {
        if (p[i] > p[i + 1]) {
            int idx = i + 2;
            while (idx < n) {
                if (p[idx] > p[i]) {
                    break;
                }
                idx++;
            }
            idx--;
            swap(p[i], p[idx]);
            
            for (int j = 0; j <= i; j++) {
                cout << p[j] << ' ';
            }
            for (int j = n - 1; j > i; j--) {
                cout << p[j] << ' ';
            }
            break;
        }
    }

    cout << endl;

    return 0;
}