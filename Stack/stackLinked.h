//
// Created by marwan on 6/1/20.
//

#ifndef STACK7_STACKLINKED_H
#define STACK7_STACKLINKED_H
#include <iostream>
#include <cassert>
#include "stackADT.h"


template<class type>
class stackLinked : public stackADT<type> {
public:
    const stackLinked<type> &operator=(const stackLinked<type> &);

    void initializeStack();

    bool isEmptyStack() const;

    bool isFullStack() const;

    void push(const type &newItem);

    type top() const;

    void pop();

    stackLinked();

    stackLinked(const stackLinked<type> &otherStack);

    ~stackLinked();

    bool operator==(const stackLinked<type>&);

    void reverseStack(stackLinked<type>&);
    void print();

private:
    struct node {
        node* next;
        type data;
    };
    node* topEle;
    int size;
    void copyStack(const stackLinked<type>& otherStack);
};


#endif //STACK7_STACKLINKED_H