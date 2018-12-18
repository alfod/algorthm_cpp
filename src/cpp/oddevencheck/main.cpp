//
// Created by Administrator on 2018/12/11.
//
#include <iostream>

using namespace std;

int main() {
    int array[4][4] = {
            {1, 0, 1, 0},
            {0, 1, 0, 0},
            {1, 1, 1, 1},
            {0, 1, 0, 1}
    };

    int rowLength = sizeof(array) / sizeof(array[0]);
    int colLength = sizeof(array[0]) / sizeof(array[0][0]);
    int errorRow[rowLength], errorCol[colLength], errorNum = 0;
    int *row, r, i, j, tmpIndex = 0;
    for (i = 0; i < rowLength; i++) {
        row = array[i];
        r = 0;
        for (j = 0; j < colLength; j++) {
            r ^= array[i][j];
        }
        if (r % 2 == 1) {
            errorRow[errorNum++] = i+1;
        }
    }
    errorNum = 0;
    for (i = 0; i < colLength; i++) {
        r = 0;
        for (j = 0; j < rowLength; j++) {
            r ^= array[j][i];
        }
        if (r % 2 == 1) {
            errorCol[errorNum++] = i+1;
        }
    }
    if (errorNum == 0) {
        cout << "OK" << endl;
    }
    if (errorNum == 1) {
        cout << "change bif (" << errorRow[0] <<", "<< errorCol[0] << ")" << endl;
    }
    if (errorNum > 1) {
        cout << "error " << endl;
    }
}
