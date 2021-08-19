#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100;
const int maxS = 5000;
int e[maxN][maxN] = {{0}};
int f[maxN][maxN] = {{0}};
int s[maxS] = {0};

int main() 
{
    int n = 0;
    cin >> n; 

    int s2 = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> e[i][j];
            f[i][j] = e[i][j];

            if (e[i][j] != 0) {
                s2++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (e[i][j] != 0) {
                s[i] =
            }
        }
    }

    int result = 0;
    int cnt = 0;
    s2 /= 2;
    for (int i = 0; i < s2; i++) {

    }

    return 0;
}