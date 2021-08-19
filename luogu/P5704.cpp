/*
题目描述
输入一个小写字母，输出其对应的大写字母。例如输入 q[回车] 时，会输出 Q。
*/

#include <iostream>

using namespace std;

int main()
{
    char c = ' ';
    cin >> c;

    char result = c - 'a' + 'A';

    cout << result << endl;

    return 0;
}