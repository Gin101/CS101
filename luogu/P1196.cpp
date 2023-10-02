#include <iostream>
#include <cmath>

using namespace std;

const int maxIJ = 30000;
int f[maxIJ] = {0};
int front[maxIJ] = {0};
int num[maxIJ] = {0};
int find(int x) {                                       
    if (f[x] == x) {
        return f[x];
    }

    int idx = find(f[x]);
    front[x] += front[f[x]];
    return f[x] = idx;
}
int main()
{
    int t = 0;
    cin >> t;

    for (int i = 0; i < 30000; i++) {
        f[i] = i;
        num[i] = 1;
    }

    for (int i = 0; i < t; i++) {
        char c;
        int I = 0;
        int J = 0;
        cin >> c >> I >> J;

        I--;
        J--;
        int idxI = find(I);                                    
        int idxJ = find(J);                                     
        if (c == 'M') {
            front[idxI] += num[idxJ];        
            f[idxI] = idxJ;                                    
            num[idxJ] += num[idxI];                            
            num[idxI] = 0;                        
        } else {
            if (idxI != idxJ) {
                cout << -1 << endl;
            } else {
                cout << abs(front[I] - front[J]) - 1 << endl;
            }
        }
    }

    return 0;
}