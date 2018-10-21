//
// Created by Administrator on 2018/10/19.
//

#ifndef CDEMO98_STACK_H
#define CDEMO98_STACK_H

const int maxSize = 50;

template<class T>
class Stack {
public :
    Stack() {};

    virtual void Push(const T &x) = 0;

    virtual bool Pop(T &x) = 0;

    virtual bool Pop()=0;

    virtual bool getTop(T &x) const = 0;

    virtual bool IsEmpty() const = 0;

    virtual bool IsFull() const = 0;

    virtual int getSize() const = 0;
};

#endif //CDEMO98_STACK_H
