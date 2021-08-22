#include <iostream>
#include <cmath>

using namespace std;

const int maxXY = 1e5;
const int maxS = 2e5;
int row[maxXY] = {0};
int col[maxXY] = {0};
int dif[maxXY] = {0};
int dif2[maxXY] = {0};
int sum[maxS] = {0};

int main()
{
    int n = 0;
    int k = 0;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int x = 0;
        int y = 0;
        cin >> x >> y;

        row[x - 1]++;

        if (row[x - 1] == k) {
            cout << i + 1 << endl;
            break;
        }

        col[y - 1]++;

        if (col[y - 1] == k) {
            cout << i + 1 << endl;
            break;
        }

        if (y > x) {
            dif[y - x]++;
            if (dif[y - x] == k) {
                cout << i + 1 << endl;
                break;
            }   
        } else if (x > y){
            dif2[x - y]++;
            if (dif2[x - y] == k) {
                cout << i + 1 << endl;
                break;
            }
        } else {
            dif[0]++;
            dif2[0]++;
            if (dif[0] == k) {
                cout << i + 1 << endl;
                break;
            }

            if (dif2[0] == k) {
                cout << i + 1 << endl;
                break;
            }
        }

        sum[x + y - 1]++;
        if (sum[x + y - 1] == k) {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}