/*
题目描述
输入一个不小于 100 且小于 1000，同时包括小数点后一位的一个浮点数，例如123.4，要求把这个数字翻转过来，变成4.321并输出。
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;

    for (int i = s.size() - 1; i >= 0; i--) {
        cout << s[i];
    }

    cout << endl;

    return 0;
}