#include <iostream>

using namespace std;

const int maxNAB = 200;
int a[maxNAB] = {0};
int b[maxNAB] = {0};
int win[5][5] = {
    {0,0,1,1,0},
    {1,0,0,1,0},
    {0,1,0,0,1},
    {0,0,1,0,1},
    {1,1,0,0,0}
};
int main() 
{
    int n = 0;
    int na = 0;
    int nb = 0;
    cin >> n >> na >> nb;

    for (int i = 0; i < na; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < nb; i++) {
        cin >> b[i];
    }
    
    int resultA = 0;
    int resultB = 0;
    int tmpa = 0;
    int tmpb = 0;
    
    for (int i = 0; i < n; i++) {
        resultA += win[a[tmpa]][b[tmpb]];
        resultB += win[b[tmpb]][a[tmpa]];
        tmpa = (tmpa + 1) % na;
        tmpb = (tmpb + 1) % nb;
    }
    
    cout << resultA << ' ' << resultB << endl;
    
    return 0;
}