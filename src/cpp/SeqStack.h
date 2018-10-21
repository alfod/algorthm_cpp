//
// Created by Administrator on 2018/10/20.
//

#ifndef CDEMO98_SEQSTACK_H
#define CDEMO98_SEQSTACK_H

#include "Stack.h"
#include <iostream>
#include <ostream>
#include <assert.h>

using namespace std;
const int elementIncrement = 20;

template<class T>
class SeqStack;

template<class T>
ostream &operator<<(ostream &os, SeqStack<T> &seqStack);

template<class T>
class SeqStack : public Stack<T> {
public:
    SeqStack(int sz = 50);

    ~SeqStack() { delete[] elements; };

    void Push(const T &x);

    bool Pop(T &x);

    bool Pop();

    bool getTop(T &x) const;

    bool IsEmpty() const { return top <= -1; };

    bool IsFull() const { return (maxSize - 1) == top; }

    int getSize() const { return top + 1; }

    void MakeEmpty() { top = -1; }

    friend ostream &operator<<<>(ostream &os, SeqStack<T> &seqStack);

    string toString() const;

private:
    T * elements;
    int top;
    int maxSize;

    void overFLowProcess();
};

#include "SeqStack.tpp"

#endif //CDEMO98_SEQSTACK_H
