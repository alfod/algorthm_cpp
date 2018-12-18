//
// Created by Administrator on 2018/12/12.
//

#include <iostream>

using namespace std;


void hanoi(int n, char A, char B, char C) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, A, C, B);
    cout << "movie " << n << " from " << A << " to " << B << endl;
    hanoi(n - 1, C, B, A);
}

int main() {
    hanoi(3, 'A', 'B', 'C');
}

