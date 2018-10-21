//
// Created by Administrator on 2018/10/20.
//

#include "Calculator.h"
#include "SeqStack.h"
#include <cstdarg>
#include <map>
#include <cstdlib>
#include <sstream>

using namespace std;


map<string, int> buildMap(const int count, ...) {
    va_list arg_ptr;
    va_start(arg_ptr, count);
    map<string, int> aMap;
    string cs[count / 2];
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
        aMap.insert(pair<string, int>(cs[i], csWeight[i]));
    }
    va_end(arg_ptr);
    return aMap;
}

void stackMoveTo(SeqStack<string> &source, SeqStack<string> &destination) {
    //cout << "destination    " << destination << endl;
    string topString;
    for (int j = 0; !source.IsEmpty(); ++j) {
        source.Pop(topString);
        //cout << "topString    " << topString << endl;
        if (topString == "(") {
            break;
        }
        destination.Push(topString);
    }
    //cout << "destination    " << destination << endl;
    // return destination;
}

template<class NUMBER>
NUMBER stringToNum(const string &s) {
    istringstream iss(s);
    NUMBER number;
    iss >> number;
    return number;
}

template<class NUMBER>
string numToString(NUMBER number) {
    ostringstream oss;
    oss << number;
    return oss.str();
}

bool IsNumber(char &c) {
    return (c >= '0' && c <= '9') || c == '.';
}

double Calculator::calculate(string s) {
    if (s.length() < 1) {
        return 0;
    }
    //set<char> operators = buildSet(6, '+', '-', '*', '/', '(', ')');
    map<string, int> inStackWeights = buildMap(12, '+', 3, '-', 3, '*', 4, '/', 4, '(', 5, ')', 2);
    // map<string, int> inStackWeights1{{string "-", 3}, {"*", 4}, {"/", 4}, {"(", 5}, {")", 2}};
    map<string, int> outStackWeights = buildMap(12, '+', 3, '-', 3, '*', 4, '/', 4, '(', 2, ')', 5);
    SeqStack<string> operatorStack;
    SeqStack<string> resultStack;
    char topChar, sChar;
    int topWeight, sCharWeight;
    bool needPush = false;
    string subString, topString;
    for (unsigned int i = 0; i < s.length(); ++i) {
        sChar = s.at(i);
        if (IsNumber(sChar) && i != s.length() - 1) {
            //number
            for (unsigned int j = i + 1; j < s.length(); ++j) {
                topChar = s.at(j);
                if (!IsNumber(topChar) || j == s.length() - 1) {
                    subString = s.substr(i, j - i);
                    i = j - 1;
                    break;
                }
            }
        } else {
            subString = string(1, sChar);
        }
        //cout << "subString   " << subString << endl;
        if (outStackWeights.count(subString) == 1) {
            //cout << "operatorStack   " << operatorStack << endl;
            if (subString == ")") {
                stackMoveTo(operatorStack, resultStack);
                needPush = false;
            } else if (operatorStack.getTop(topString)) {
                topWeight = inStackWeights.at(topString);
                sCharWeight = outStackWeights.at(subString);
                needPush = sCharWeight >= topWeight;
                if (!needPush && (subString != "(" && topString != "(")) {
                    operatorStack.Pop(topString);
                    resultStack.Push(topString);
                }
                operatorStack.Push(subString);
            } else {
                operatorStack.Push(subString);
            }

        } else {
            resultStack.Push(subString);
            if (needPush) {
                stackMoveTo(operatorStack, resultStack);
                needPush = false;
            }
        }
    }
    stackMoveTo(operatorStack, resultStack);
    cout << resultStack << endl;

    string reChar, left, right, oper;
    SeqStack<string> tmpStack;
    SeqStack<string> tmp1Stack;
    stackMoveTo(resultStack, tmpStack);

    double result = 0, leftNum, rightNum;
    for (int j = 0; tmpStack.getSize() > 0; ++j) {
        tmpStack.Pop(reChar);
        if (inStackWeights.count(reChar) == 0) {
            //number
            tmp1Stack.Push(reChar);
        } else {
            //operator
            oper = reChar;
            tmp1Stack.Pop(right);
            tmp1Stack.Pop(left);
            leftNum = stringToNum<double>(left);
            rightNum = stringToNum<double>(right);
            if (oper == "+") {
                result = leftNum + rightNum;
            }
            if (oper == "-") {
                result = leftNum - rightNum;
            }
            if (oper == "*") {
                result = leftNum * rightNum;
            }
            if (oper == "/") {
                result = leftNum / rightNum;
            }
            tmp1Stack.Push(numToString(result));
        }
    }
    cout << "result  " << tmp1Stack << endl;

}




