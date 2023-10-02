#include <iostream>
#include <vector>

using namespace std;

const int maxN = 30;
int n = 0;
int m = 0;
char a[maxN][maxN];
char b[maxN][maxN];
int num[maxN * 2 | 1][maxN] = {{0}};

int gcd(int x, int y) {
    return y ? gcd(y, x % y) : x;
}

void update(int idx, int row, int val) {
    num[idx += n][row] = val; 
    while (idx != 1) {
        idx /= 2;
        num[idx][row] = gcd(num[idx * 2][row], num[idx * 2 | 1][row]);
    }
}

int query(int idx, int row, int val) {
    idx += n;
    while (idx != 1 && num[idx][row] % val == 0) {
        if (__builtin_popcount(idx + 1) == 1) {
            return n + 1;
        }
        idx = (idx + 1) / 2;
    }

    while (idx < n) {
        idx *= 2;
        idx += (num[idx][row] % val == 0);
    }
    return idx - n;
}

bool match(int s, int t) {
    vector<vector<int> > a_gcd(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a_gcd[i][j] = a[i][(j + t) % m];
        }
        for (int j = 0; j < m; j++) {
            update(i, j, a_gcd[i][j]);
        }
    }

    vector<vector<int> > b_gcd(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            b_gcd[i][j] = b[(i + s) % n][j];
        }
        for (int j = 0; j < m; j++) {
            if (query(i, j, b_gcd[i][j]) != n) {
                return false;
            }
        }
    }

    return true;
}

int main() 
{
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }

    for (int s = 0; s < n; s++) {
        for (int t = 0; t < m; t++) {
            if (match(s, t)) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;

    return 0;
}