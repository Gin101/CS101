#include <iostream>
#include <set>

using namespace std;

const int maxN = 1e6;
int a[maxN] = {0};
int main() 
{
    int t = 0;
    cin >> t;
    
    int n = 0;
    for (int i = 0; i < t; i++) {
        if (i == 0) {
            cin >> n;
            for (int j = 1; j <= n; j++) {
            	cin >> a[j];
            }
        } else {
            int k = 0;
            cin >> k;
            
            for (int j = 0; j < k; j++) {
            	int x = 0;
            	int y = 0;
                cin >> x >> y;
                
                a[x] = y;
            }
        }
        
        set<pair<int, int> > s;
        for (int i = 1; i <= n; i++) {
            s.insert({a[i], i});
        }
        
        int tmp = 0;
        int result = 0;;
        while (true) {
            if (s.size() == 2) {
                s.erase(s.begin());
                if (tmp != 0) {
                    if ((tmp - s.size()) % 2) {
                        result = tmp + 1;
                    } else {
                        result = tmp;
                    }
                } else {
                	result = 1;
                }
                break;
            }
            
            set<pair<int, int> >::iterator p = s.end();
            p--;
            int x = p -> first;
            int idx = p -> second;
            int y = s.begin() -> first;
            
            s.erase(p);
            s.erase(s.begin());
            s.insert({x - y, idx});
            if (s.begin() -> second != idx) {
                if (tmp != 0) {
                    if ((tmp - s.size()) % 2) {
                        result = tmp + 1;
                    } else {
                        result = tmp;
                    }
                    break;
                }
            } else {
                if (tmp == 0) {
                	tmp = s.size();
                }
            }
        }
    	
    	cout << result << endl;
    }
    
    return 0;
}