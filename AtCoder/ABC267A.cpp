#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    switch(s[1]) {
        case 'o': {
            cout << 5 << endl;
            break;
        } case 'u': {
            cout << 4 << endl;
            break;
        } case 'e': {
            cout << 3 << endl;
            break;
        } case 'h': {
            cout << 2 << endl;
            break;
        } case 'r': {
            cout << 1 << endl;
        }
    }

    return 0;
}