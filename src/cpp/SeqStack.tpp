//
// Created by Administrator on 2018/10/20.
//

#include "SeqStack.h"
#include <typeinfo>

using namespace std;

template<class T>
SeqStack<T>::SeqStack(int sz) : top(-1), maxSize(sz) {
    elements = new T[sz];
}

template<class T>
void SeqStack<T>::overFLowProcess() {
    T *newArray = new T[maxSize + elementIncrement];
    assert(newArray != NULL);
    for (int i = 0; i <= top; ++i) {
        newArray[i] = elements[i];
    }
    maxSize = maxSize + elementIncrement;
    delete[] elements;
    elements = newArray;
}

template<class T>
void SeqStack<T>::Push(const T &x) {
    if (IsFull()) {
        overFLowProcess();
    }
    elements[++top] = x;
}

template<class T>
bool SeqStack<T>::Pop(T &x) {
    if (IsEmpty()) {
        return false;
    }
    x = elements[top--];
    return true;
}

template<class T>
bool SeqStack<T>::Pop() {
    if (IsEmpty()) {
        return true;
    }
    top--;
    return true;
}

template<class T>
bool SeqStack<T>::getTop(T &x) const {
    if (IsEmpty()) {
        return false;
    }
    x = elements[top];
    return true;
}


template<class T>
ostream &operator<<(ostream &os, SeqStack<T> &seqStack) {
    os << "top=" << seqStack.top << endl;
    for (int i = 0; i <= seqStack.top; ++i) {
        os << i << " : " << seqStack.elements[i] << endl;
    }
    return os;
}

template<class T>
string SeqStack<T>::toString() const {
    string s;
    for (int i = top; i >= 0; --i) {
        s += elements[i];
    }
    return s;
}


