//
// Created by Administrator on 2018/12/18.
//

#include <iostream>

using namespace std;

const int T = 8;

int main() {

    int i, j, k = 1;

    for (i = 1; i <= T; i += 2)
        for (j = 2; j <= T; j++)
            if (i + j == T)
                cout << '+';
            else if (i * j == T)
                cout << '*';
            else
                k++;
    cout << endl << "k=" << k << endl;

}
