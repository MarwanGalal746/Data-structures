//
// Created by marwan on 6/1/20.
//

#ifndef STACK7_STACKARR_H
#define STACK7_STACKARR_H
#include <iostream>
#include <cassert>
#include "stackADT.h"

template<class type>
class stackArr : public stackADT<type> {
    const stackArr<type> &operator=(const stackArr<type> &);

    void initializeStack();

    bool isEmptyStack() const;

    bool isFullStack() const;

    void push(const type &newItem);

    type top() const;

    void pop();

    explicit stackArr(int stackSize = 100);

    stackArr(const stackArr<type> &otherStack);

    ~stackArr();


private:
    int topEle;
    int size;
    type* arr;
    void copyStack(const stackArr<type>& otherStack);
};


#endif //STACK7_STACKARR_H