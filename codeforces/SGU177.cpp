#include <iostream>
#include <algorithm>

using namespace std;

int n = 0;
int m = 0;
int sum = 0;
const int maxN = 5001;
int gx[maxN][2] = {{0}};
int gy[maxN][2] = {{0}};
bool color[maxN] = {0};
 
void make (int p, int x1, int x2, int y1, int y2) {
    while (p <= m && (x1 > gx[p][1] || x2 < gx[p][0] || y1 > gy[p][1] || y2 < gy[p][0])) {
        p++;
    }
    
    if (p == m + 1) {
        sum += (x2 - x1 + 1) * (y2 - y1 + 1);
        return;
    }
    
    int k1 = max(x1, gx[p][0]);
    int k2 = min(x2, gx[p][1]);
    if (x1 < k1) {
        make(p + 1, x1, k1 - 1, y1, y2);
    }
    if (x2 > k2) {
        make(p + 1, k2 + 1, x2, y1, y2);
    }

    x1 = k1;
    x2 = k2;
 
    k1 = max(y1, gy[p][0]);
    k2 = min(y2, gy[p][1]);
    if (y1 < k1) {
        make(p + 1, x1, x2, y1, k1 - 1);
    }
    if (y2 > k2) {
        make(p + 1, x1, x2, k2 + 1, y2);
    }
}
int main() 
{
    cin >> n >> m;
    
    for (int i = 1; i <= m; i++) {
        int x = 0;
        int y = 0;
        int x2 = 0;
        int y2 = 0;
        char c = 0;
        cin >> x >> y >> x2 >> y2 >> c;

        gx[i][0] = min(x, x2);
        gy[i][0] = min(y, y2);
        gx[i][1] = max(x, x2);
        gy[i][1] = max(y, y2);
        color[i] = (c == 'b') ? true : false;
    }
    
    for (int i = m; i > 0; i--) {
        if (color[i]) {
            make(i + 1, gx[i][0], gx[i][1], gy[i][0], gy[i][1]);
        }
    }
   
    cout << n * n - sum << endl;

    return 0;
}