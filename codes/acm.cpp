#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

int n = 0;
const int maxN = 300;
int conquer = 0;
int ncon = 0;

struct Planet {
	int power;
	int dp;
};

bool cmp(Planet x, Planet y) {
    if (x.dp < 0) {
        int valX = x.power + x.dp;
        int valY = y.power + y.dp;
        if (valX == valY) {
            return x.power > y.power;
        }

        return valX > valY;
    }

    return x.power < y.power;
}

void dfs(Planet p[], int ncp, int idx, int move, int n) {
	cout << "move: " << move << ", init cp: " << ncp << endl;
	for (int i = idx; i < n; i++) {
		if (ncp > p[i].power && ncp + p[i].dp > 0) {
			cout << "move: " << move << ", i: " << i << endl;
            printf("cp: %d, p[%d].power: %d, newCP: %d\n", ncp, i, p[i].power, ncp + p[i].dp);
            printf("ncon: %d -> ", ncon);
			ncon = max(ncon, move + 1);
            printf("ncon: %d\n", ncon);

			dfs(p, ncp + p[i].dp, i + 1, move + 1, n);
		}
	}
} 

int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	
	int cp = 0;//catPower
	cin >> n >> cp;

    Planet p1[maxN] = {0};
    Planet p2[maxN] = {0};
    int cnt1 = 0;
    int cnt2 = 0;

	for (int i = 0; i < n; i++) {
		int power = 0;
		int dp = 0;//diePower
		
		cin >> power >> dp;
        if (dp < 0) {
            p2[cnt2].power = power;
            p2[cnt2].dp = dp;
            cnt2++;
        } else {
            p1[cnt1].power = power;
            p1[cnt1].dp = dp;
            cnt1++;
        }
	}
	
    sort(p1, p1 + cnt1, cmp);

	// for (int i = 0; i < cnt1; i++) {
	// 	cout << p1[i].power << ' ' << p1[i].dp << endl;
	// }

    for (int i = 0; i < cnt1; i++) {
        if (cp > p1[i].power && cp + p1[i].dp > 0) {
            conquer++;
            cp += p1[i].dp;
        }
    }

    sort(p2, p2 + cnt2, cmp);
	
    for (int i = 0; i < cnt2; i++) {
		cout << p2[i].power << ' ' << p2[i].dp << endl;
	}
	
    dfs(p2, cp, 0, 0, cnt2);
    conquer += ncon;
	
	cout << conquer << endl;

	return 0;
}
