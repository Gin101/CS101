#include <iostream>
#include <string>

using namespace std;

string dfs() {
	int n = 0;
	string s = "";
	string s2 = "";
	
	char c = ' ';
	while (cin >> c) {
		if (c == '[') {
			cin >> n;
			s2 = dfs();
			for (int i = 0; i < n; i++) {
				s += s2;
			}
		} else {
			if (c==']')  {
				return s;
			} else {
				s += c;
			}
		}
	}
}
int main()
{
	cout << dfs(); 
	
	return 0;
}
