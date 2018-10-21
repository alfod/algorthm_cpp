//
// Created by Administrator on 2018/10/20.
//

#include "Calculator.h"
#include "SeqStack.h"
#include <set>
#include <cstdarg>
#include <map>

using namespace std;

set<char> buildSet(int count, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, count);
    set<char> aSet;
    for (int i = 0; i < count; i++) {
        aSet.insert(va_arg(arg_ptr, int));
    }
    va_end(arg_ptr);
    return aSet;
}


map<char, int> buildMap(const int count, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, count);
    map<char, int> aMap;
    char cs[count / 2];
    int csWeight[count / 2];
    int index;
    for (int i = 0; i < count; i++) {
        index = i / 2;
        int mod = i % 2;
        if (mod == 0) {
            cs[index] = (char) va_arg(arg_ptr, int);
            // cout << cs[index] << endl;
        } else {
            csWeight[index] = va_arg(arg_ptr, int);
            //cout << csWeight[index] << endl;
        }
    }

    for (int i = 0; i < count / 2; i++) {
        aMap.insert(pair<char, int>(cs[i], csWeight[i]));
    }
    va_end(arg_ptr);
    return aMap;
}

double Calculator::calculate(string s) {
    if (s.length() < 1) {
        return 0;
    }
    //set<char> operators = buildSet(6, '+', '-', '*', '/', '(', ')');
    map<char, int> inStackWeights = buildMap(12, '+', 3, '-', 3, '*', 4, '/', 4, '(', 2, ')', 5);
    //map<char, int> outStackWeights = buildMap(12, '+', 3, '-', 3, '*', 4, '/', 4, '(', 2, ')', 5);
    SeqStack<char> operatorStack;
    SeqStack<char> resultStack;
    char topChar, sChar;
    int topWeight, inWeight;
    bool needPush = false;
    for (unsigned int i = 0; i < s.length(); ++i) {
        sChar = s.at(i);
        if (inStackWeights.count(sChar) == 1) {
            if (operatorStack.getTop(topChar)) {
                topWeight = inStackWeights.at(topChar);
                inWeight = inStackWeights.at(sChar);
                needPush = inWeight > topWeight;
            }
            operatorStack.Push(sChar);
        } else {
            resultStack.Push(sChar);
            cout << "operatorStack ; " << operatorStack << endl;
            cout << "resultStack ; " << resultStack << endl;
            if (needPush) {
                char tmpTopChar;
                operatorStack.getTop(tmpTopChar);
                for (int j = 0; !operatorStack.IsEmpty(); ++j) {
                    operatorStack.getTop(topChar);
                    if (topChar == ')') {
                        operatorStack.Pop(topChar);
                        continue;
                    }
                    if (topChar == '(') {
                        if (tmpTopChar == ')') {
                            operatorStack.Pop(topChar);
                        }
                        break;
                    }
                    // operatorStack.Pop(topChar);
                    resultStack.Push(topChar);
                }
                needPush = false;
            }
        }
    }
    cout << resultStack << endl;
}
