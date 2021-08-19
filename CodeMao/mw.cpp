#include <iostream>

using namespace std;

const int maxN = 100001;
int a[maxN] = {0};
int b[maxN] = {0};//box
int idx = 0;

void up(int x) {
    while(b[x] > b[x / 2] && x / 2 > 0) {
        swap(b[x], b[x / 2]);
        x /= 2;
    }
}

void down(int x) {
    while ((b[x] < b[x * 2] && x * 2 <= idx) || (b[x] < b[x * 2 + 1] && x * 2 + 1 <= idx)) {
        if (x * 2 == idx || b[x * 2] > b[x * 2 + 1]) {
            swap(b[x], b[x * 2]);
            x *= 2;
        } else {
            swap(b[x], b[x * 2 + 1]);
            x = x * 2 + 1;
        }
    }
}

int main()
{
    int n = 0;
    int m = 0;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    for (int i = 1; i <= n; i++) {
        b[++idx] = a[i];
        up(idx);
    }
    
    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (a[i] > 0) {
            flag = false;
            break;
        }
    }
    
    int result = 0;
    if (flag) {
        cout << 0 << endl;
    } else {
    	while(true) {
	        result++;
	        b[1] -= m - 1;
	        down(1);
	        if (b[1] <= result) {
	        	break;
	        } else {
	        	b[1]--;
	        }
	    }
    }
    
    cout << result << endl;
    
    return 0;
}