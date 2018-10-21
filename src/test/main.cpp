#include <iostream>
#include <set>
#include <cstdarg>
#include <map>
#include "../cpp/SeqStack.h"
#include "../cpp/Calculator.h"

using namespace std;
//
//set<char> buildSet(int count, ...) {
//    va_list arg_ptr;
//    va_start(arg_ptr, count);
//    set<char> aSet;
//    for (int i = 0; i < count; i++) {
//        aSet.insert(va_arg(arg_ptr, int));
//    }
//    va_end(arg_ptr);
//    return aSet;
//}

set<char> buildSet(int count, ...);

map<char, int> buildMap(int count, ...);

void calculator() {
    Calculator::calculate("1+(1-2)*4+2/8");
}

int main() {
//    map<char, int> aSet = buildMap(6, 'q', 1, 'a', 2, 'r', 3);
//    for (map<char, int>::iterator iterator1 = aSet.begin();
//         iterator1 != aSet.end(); iterator1++) {
//        cout << iterator1->first << " : "<<iterator1->second << endl;
//    }

    calculator();

    //1 1 + 2 4 * - 2 8 / +
    return 0;
}


void seqStack() {
    SeqStack<int> stack(30);
    stack.Push(12);
    cout << stack << endl;
    int i;
    stack.getTop(i);
    cout << i << endl;

    stack.Pop(i);
    cout << i << endl;

    cout << stack << endl;
}



