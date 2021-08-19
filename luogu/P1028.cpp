#include <iostream>

using namespace std;

const int maxN = 1000;
int num[maxN] = {0};

int main()
{
	int n = 0;
    cin >> n;
    
    for(int i = 0; i < n; i++) { 
        for(int j = 0; j < (i + 1) / 2; j++) {
            num[i] += num[j]; 
        }
        num[i]++; 
    }
    
    cout << num[n - 1] << endl;
    
    return 0;
}
