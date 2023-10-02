#include <iostream>

using namespace std;

const int maxN = 100;
int player[maxN] = {0};;

int main()
{
    int n = 0;
    int q = 0;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int c = 0;
        int x = 0;
        cin >> c >> x;

        switch (c) {
            case 1: {
                player[x - 1]++;
                break;
            } case 2: {
                player[x - 1] += 2;
                break;
            } case 3: {
                if (player[x - 1] >= 2) {
                    cout << "Yes" << endl;
                } else {
                    cout << "No" << endl;
                }
            }
        }
    }

    return 0;
}