//
// Created by Administrator on 2018/12/11.
//
#include <iostream>
#include "Tree.h"

using namespace std;

int main() {
    cout << "please enter pre-order:" << endl;
    char preOrder[20];
    cin >> preOrder;
    cout << "your pre-order is " << preOrder << endl;

    cout << "please enter in-order:" << endl;
    char inOrder[20];
    cin >> inOrder;
    cout << "your in-order is " << inOrder << endl;
    char result[strlen(preOrder)];
    Tree::PostOrder(preOrder, inOrder,result);
    cout << "post-order is " << result << endl;

}
