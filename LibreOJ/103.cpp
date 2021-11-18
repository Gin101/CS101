#include <iostream>
#include <string>

using namespace std;

const int P = 131;

int main() 
{
    string a;
    string b;
    cin >> a >> b;

    if (b.size() > a.size()) {
        cout << 0 << endl;
        return 0;
    }

    long long ha = 0;
    long long hb = 0;
    long long t = 1;

    for (int i = 0; i < b.size(); i++) {
        ha = ha * P + a[i],
        hb = hb * P + b[i],
        t *= P;
    }

    int result = (ha == hb);
    for (int i = b.size(); i < a.size(); i++) {
        ha = ha * P + a[i] - t * a[i - b.size()];
        result += (ha == hb);
    }

    cout << result << endl;
}