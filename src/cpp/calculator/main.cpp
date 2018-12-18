//
// Created by Administrator on 2018/12/17.
//

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char inchars[201];
    cin.getline(inchars, 201);
    double nums[101], num = 0.0, result[101];
    int charLength = strlen(inchars), incharIndex = 0, numIndex = 0;
    while ('0' <= inchars[incharIndex] && inchars[incharIndex] <= '9') {
        num = num * 10 + inchars[incharIndex++] - '0';
    }
    nums[numIndex++] = num;
    char oper;
    while (incharIndex < charLength) {
        num = 0.0;
        oper = inchars[incharIndex++];
        while ('0' <= inchars[incharIndex] && inchars[incharIndex] <= '9') {
            num = num * 10 + inchars[incharIndex++] - '0';
        }
        if (oper == '-') {
            nums[numIndex++] = -num;
        }
        if (oper == '+') {
            nums[numIndex++] = num;
        }
        if (oper == '*') {
            nums[numIndex - 1] *= num;
        }
        if (oper == '/') {
            nums[numIndex - 1] /= num;
        }
    }
    num = 0.0;
    for (int i = 0; i < numIndex; i++) {
        num += nums[i];
    }
    cout << "num = " << fixed << setprecision(2) << num << endl;
}
