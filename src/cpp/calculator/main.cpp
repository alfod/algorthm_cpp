//
// Created by Administrator on 2018/12/17.
//

#include <iostream>
#include <iomanip>

using namespace std;

double calculator(char inchars[]) {
    double nums[101], result = 0.0;
    int charLength = strlen(inchars), incharIndex = 0, numIndex = 0;
    while ('0' <= inchars[incharIndex] && inchars[incharIndex] <= '9') {
        result = result * 10 + inchars[incharIndex++] - '0';
    }
    nums[numIndex++] = result;
    char oper;
    while (incharIndex < charLength) {
        result = 0.0;
        oper = inchars[incharIndex++];
        while ('0' <= inchars[incharIndex] && inchars[incharIndex] <= '9') {
            result = result * 10 + inchars[incharIndex++] - '0';
        }
        if (oper == '-') {
            nums[numIndex++] = -result;
        }
        if (oper == '+') {
            nums[numIndex++] = result;
        }
        if (oper == '*') {
            nums[numIndex - 1] *= result;
        }
        if (oper == '/') {
            nums[numIndex - 1] /= result;
        }
    }
    result = 0.0;
    for (int i = 0; i < numIndex; i++) {
        result += nums[i];
    }
    return result;
}

int main() {
    char *inchars;
    char *array[101];
    int arrayLength = 0, arrayIndex = 0;
    while (true) {
        inchars = new char[101];
        cin.getline(inchars, 201);
        if (strlen(inchars) == 1 && inchars[0] == '0') {
            break;
        }
        array[arrayLength++] = inchars;
    };
    while (arrayIndex < arrayLength) {
        double result = calculator(array[arrayIndex++]);
        cout << fixed << setprecision(2) << result << endl;
    }
}
