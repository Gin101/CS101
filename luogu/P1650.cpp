#include <iostream>
#include <algorithm>

using namespace std;
const int maxN = 10001;
int r[maxN] = {0};
int b[maxN] = {0};
int main() 
{
    int n = 0;
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    int result = 0;
    sort(r + 1, r + n + 1, greater<int>());
    sort(b + 1, b + n + 1, greater<int>());
    int st = 1, ed = n;
	for (int i = 1, j = n; i <= j;) {
		if (r[ed] > b[j]) {
		    result++;
		    ed--;
		    j--;
		} else if (r[ed] < b[j]) {
			result--;
		    ed--;
		    i++;
		} else if (r[st] > b[i]) {
		    result++;
		    st++;
		    i++;
		} else if (r[st] < b[i]) {
			result--;
		    ed--;
		    i++;
		} else {
		    result -= (r[ed] < b[i]);
		    ed--;
		    i++;
		}
	}
	cout << result * 200 << endl;
	
    return 0;
}