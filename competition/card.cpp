#include <iostream>

using namespace std;

const int maxN = 400;

struct Card {
    int v = 0;
    int b = 0;
} c[maxN], tmp[maxN];

bool cmpv (Card x, Card y) {
    if (x.v > 0 || y.v > 0) {
        return x.v < y.v;
    } else {
        return (x.v + x.b) < (y.v + y.b); 
    }
}

bool cmpb (Card x, Card y) {
    if (x.b > 0 || y.b > 0) {
        return x.b < y.b;
    } else {
        return (x.v + x.b) < (y.v + y.b); 
    }
}

int main()
{
    int n = 0;
    cin >> n;       

    int resultv = 0;
    int resultb = 0;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> c[i].v >> c[i].b;

        if (c[i].v > 0 && c[i].b > 0) {
            resultv += c[i].v;
            resultb += c[i].b;
        } else if (!(c[i].v <= 0 && c[i].b <= 0)) {
            tmp[idx++] = c[i];
            resultv += c[i].v;
            resultb += c[i].b;
        }
    }

    if (resultv < 0) {
        sort(tmp, tmp + idx, cmpv);

        int idx2 = 0;
        while (resultv < 0) {
            resultv -= tmp[idx2++].v;
            resultb -= tmp[idx2 - 1].b;
            idx--;
        }
    } else if (resultb < 0){
        sort(tmp, tmp + idx, cmpb);

        int idx2 = 0;
        while (resultb < 0) {
            resultv -= tmp[idx2++].v;
            resultb -= tmp[idx2 - 1].b;
            idx--;
        }
    }

    for (int i = 0; i < idx; i++) {
        if (tmp[i].v + tmp[i].b < 0 && resultv - tmp[i].v >= 0 && resultb - tmp[i].b >= 0) {
            resultv -= tmp[i].v;
            resultb -= tmp[i].b;
        }
    }

    cout << resultv + resultb << endl;

    return 0;
}