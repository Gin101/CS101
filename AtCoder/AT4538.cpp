#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxN = 2e5;
int h[maxN] = {0};
int a[maxN] = {0};

vector<long long> v;
void update(int idx, long long value) {
    while (idx < v.size()){
        v[idx] = max(v[idx], value);
        idx += (idx & (-idx));
    }
}

long long query(int idx) {
    long long result = 0;
    while (idx > 0) {
        result = max(result, v[idx]);
        idx -= (idx & (-idx));
    }
    return result;
}

long long ope(int h[], int a[], int n) {
    v.assign(n + 1, 0);
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long tmp = query(h[i] - 1) + a[i];
        result = max(result, tmp);
        update(h[i], tmp);
    }

    return result;
}

int main()
{
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cout << ope(h, a, n) << endl;

    return 0;
}