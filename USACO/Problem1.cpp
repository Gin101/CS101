#include <iostream>
#include <algorithm>

using namespace std;

const int maxNum = 7;
int number[maxNum] = {0};

int main()
{
	for (int i = 0; i < 7; i++) {
		cin >> number[i];
	}
	
	sort(number, number + 7);
	
	int a = number[0];
	int b = number[1];
	int c = number[6] - a - b;
	
	cout << a << ' ' << b << ' ' << c << endl;
	
	return 0;
}
