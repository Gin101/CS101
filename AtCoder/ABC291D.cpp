#include <iostream>

using namespace std;

const int MOD = 998244353;

int main()
{
    int n = 0;
    cin >> n;

    int a = 0;
    int b = 0;
    cin >> a >> b;
    int prea = a;
    int preb = b;
    int preResulta = 1;
    int preResultb = 1;
    int resulta = 1;
    int resultb = 1;
    for (int i = 1; i < n; i++) {
        cin >> a >> b;

        if (a != prea && a != preb) {
            resulta = preResulta + preResultb;
            resulta %= MOD;
        } else if (a == prea && a == preb) {
            resulta = 0;
        } else if (a != prea) {
            resulta = preResulta;
        } else {
            resulta = preResultb;
        }
        if (b != prea && b != preb) {
            resultb = preResulta + preResultb;
            resultb %= MOD;
        } else if (b == prea && b == preb) {
            resultb = 0;
        } else if (b != preb) {
            resultb = preResultb;
        } else {
            resultb = preResulta;
        }

        prea = a;
        preb = b;
        preResulta = resulta;
        preResultb = resultb;
    }

    cout << (resulta + resultb) % MOD << endl;

    return 0;
}