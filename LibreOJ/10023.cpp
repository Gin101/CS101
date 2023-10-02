#include <iostream>
#include <algorithm>

using namespace std;

struct as {
    int zx = 0;
    int zy = 0;
    int yx = 0;
    int yy = 0;
    int c = 0;
} a[15];

bool L[15];
int n = 0;
int result = 100;
bool H(int t) {
    for (int i = 1; i <= n; i++) {
        if (a[i].yx == a[t].zx && a[i].zy <= a[t].yy && !L[i]) {
            return false;
        }
    }
        
    return true;
}
void ope(int cr, int k, int T) {
    if (k == n) {
        result = min(result, T);
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!L[i] && H(i)) {
            L[i] = 1;
            if (a[i].c == cr) {
                ope(a[i].c, k + 1, T);
            } else {
                ope(a[i].c, k + 1, T + 1);
            }  
            L[i] = 0; 
        }
    }
}
int main() 
{
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i].zx >> a[i].zy >> a[i].yx >> a[i].yy >> a[i].c;
    }

    ope(-1, 0, 0);

    cout << result << endl;

    return 0;
}