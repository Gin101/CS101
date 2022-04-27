//
//  clock.cpp
//  
//
//  Created by jianbochen on 2022/4/26.
//

#include <iostream>
#include <stdio.h>

using namespace std;

int num[10] = {4, 5, 2, 3, 3, 1, 5, 4, 1, 2};
int num2[6] = {4, 5, 2, 3, 3, 3};

int main()
{
    freopen("clock.in", "r", stdin);
    freopen("clock.out", "w", stdout);
    
    int x = 0;
    int y = 0;
    int z = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int _x = 0;
    int _y = 0;
    int _z = 0;
    int _a = 0;
    int _b = 0;
    int _c = 0;
    cin >> x >> y >> z >> a >> b >> c >> _x >> _y >> _z >> _a >> _b >> _c;
    
    if (_c >= c) {
        _c -= c;
    } else {
        _c += (60 - c);
        _b--;
    }
    if (_b >= b) {
        _b -= b;
    } else {
        _b += (60 - b);
        _a--;
    }
    if (_a >= a) {
        _a -= a;
    } else {
        _a += (24 - a);
        _z--;
    }
    if (_z >= z) {
        _z -= z;
    } else {
        int tmp = 0;
        int result = 0;
        while (_z + tmp < z) {
            switch(_y) {
                case 1: {
                    tmp = 31;
                    break;
                } case 2: {
                    if (_x % 400 == 0 || (_x % 4 == 0 && _x % 100 != 0)) {
                        tmp = 29;
                    } else {
                        tmp = 28;
                    }
                    break;
                } case 3: {
                    tmp = 31;
                    break;
                } case 5: {
                    tmp = 31;
                    break;
                } case 7: {
                    tmp = 31;
                    break;
                } case 8: {
                    tmp = 31;
                    break;
                } case 10: {
                    tmp = 31;
                    break;
                } case 12: {
                    tmp = 31;
                    break;
                } default: {
                    tmp = 30;
                }
            }
            result++;
        }
        _z += (tmp - z);
        _y -= result;
    }
    
    if (_y >= y) {
        _y -= y;
    } else {
        _y += (12 - y);
    }
    
    for (int i = y; i <= (y + _y); i++) {
        switch((y + i) % 12) {
            case 1: {
                _z += 31;
                break;
            } case 2: {
                if (_x % 400 == 0 || (_x % 4 == 0 && _x % 100 != 0)) {
                    _z += 29;
                } else {
                    _z += 28;
                }
                break;
            } case 3: {
                _z += 31;
                break;
            } case 5: {
                _z += 31;
                break;
            } case 7: {
                _z += 31;
                break;
            } case 8: {
                _z += 31;
                break;
            } case 10: {
                _z += 31;
                break;
            } case 12: {
                _z += 31;
                break;
            } default: {
                _z += 30;
            }
        }
    }
    
    _x -= x;
    
    for (int i = x; i <= (x + _x); i++) {
        if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0)) {
            _z += 366;
        } else {
            _z += 365;
        }
    }
    
    long long result = 0;
    result += (_c / 10) * 30;
    for (int i = c / 10; i < (_c + c) / 10; i++) {
        result += num2[i];
    }
    for (int i = c % 10; i < (_c + c) % 10; i++) {
        result += num[i];
    }
    
    result += _b * 200;
    result += (_b / 10) * 30;
    for (int i = b / 10; i < (_b + b) / 10; i++) {
        result += num2[i];
    }
    for (int i = b % 10; i < (_b + b) % 10; i++) {
        result += num[i];
    }
    
    result += _a * 12200;
    result += (_a / 10) * 30;
    for (int i = a / 10; i < (_a + a) / 10; i++) {
        result += num2[i];
    }
    for (int i = a % 10; i < (_a + a) % 10; i++) {
        result += num[i];
    }
    
    result += _z * 293092;
    result += (_z / 10) * 30;
    for (int i = z / 10; i < (_z + z) / 10; i++) {
        result += num2[i];
    }
    for (int i = z % 10; i < (_z + z) % 10; i++) {
        result += num[i];
    }
    
    result += (_y / 10) * 30;
    for (int i = y / 10; i < (_y + y) / 10; i++) {
        result += num2[i];
    }
    for (int i = y % 10; i < (_y + y) % 10; i++) {
        result += num[i];
    }
    
    result += (_x / 10) * 30;
    for (int i = x / 10; i < (_x + x) / 10; i++) {
        result += num2[i];
    }
    for (int i = x % 10; i < (_x + x) % 10; i++) {
        result += num[i];
    }
    
    cout << result << endl;
    
    return 0;
}
