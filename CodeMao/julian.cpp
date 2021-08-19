#include <iostream>

using namespace std;

const int maxN = 146097;
int y[maxN] = {0};
int m[maxN] = {0};
int d[maxN] = {0};
int ope(int y, int m) {
	switch (m) {
		case 2: {
			if (y % 4 != 0) {
	    		return 28;
	    	} else if (y % 100 != 0) {
	    		return 29;
	    	} else if (y % 400 != 0) {
	    		return 28;
	    	} else {
	    		return 29;
	    	}
		} case 4: {
			return 30;
		} case 6: {
			return 30;
		} case 9: {
			return 30;
		} case 11: {
			return 30;
		} default: {
			return 31;
		}
	}
}
int main()
{
    m[0] = 1;
    d[0] = 1;
    
    for (int i = 1; i < maxN; i++) {
        d[i] = d[i - 1] + 1;
        m[i] = m[i - 1];
        y[i] = y[i - 1];
        
        if (d[i] > ope(y[i],m[i])) {
        	m[i]++;
        	d[i] = 1;
        }
        if (m[i] > 12) {
        	y[i]++;
        	m[i] = 1;
        }
    }
    
    int q = 0;
    cin >> q;
    int q2 = q;
    
    for (int i = 0; i < q2; i++) {
    	int r = 0;
    	cin >> r;

        if (r > 2299160) {
            r -= 2159351;
            q = r / maxN * 400 + 1200;
            r %= maxN;
        } else {
            q = r / 1461 * 4 - 4712;
            r %= 1461;
        }

        if (q + y[r] > 0) {
        	cout << d[r] << ' ' << m[r] << ' ' << q + y[r] << endl;
        } else {
        	cout << d[r] << ' ' << m[r] << ' ' << 1 - q - y[r] << " BC" << endl;
        }
    }
    
    return 0;
}