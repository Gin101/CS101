#include <iostream>
#include <algorithm>

using namespace std;

int t = 0;
int pc = 0;
const int maxN = 2e5;
struct Card {
    int c = 0;
    int r = 0;
    int idx = 0;
} p[maxN];

bool cmp(Card x, Card y) {
    if (x.c == t) {
        if (y.c == t) {
            return x.r > y.r;
        } else {
            return true;
        }
    } else {
        if (y.c == t) {
            return false;
        } else {
            if (x.c == pc) {
                if (y.c == pc) {
                    return x.r > y.r;
                } else {
                    return true;
                }
            } else {
                if (y.c == pc) {
                    return false;
                } else {
                    return x.r > y.r;
                }
            }   
        }
    }
}

int main()
{
    int n = 0;
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> p[i].c;
        p[i].idx = i + 1;
    }
    for (int i = 0; i < n; i++) {
        cin >> p[i].r;
    }

    pc = p[0].c;
    sort(p, p + n, cmp);

    cout << p[0].idx << endl;

    return 0;
}