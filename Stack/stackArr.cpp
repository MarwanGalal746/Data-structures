//
// Created by marwan on 6/1/20.
//

#include "stackArr.h"
using namespace std;
template<class type>
void stackArr<type>::initializeStack() {
    topEle=0;
}

template<class type>
bool stackArr<type>::isEmptyStack() const {
    return topEle==0;
}

template<class type>
bool stackArr<type>::isFullStack() const {
    return topEle==size;
}

template<class type>
void stackArr<type>::push(const type &newItem) {
    if(!isFullStack())
        arr[topEle++]=newItem;
    else
        cout<<"stack is full\n";
}


template<class type>
type stackArr<type>::top() const {
    assert(!isEmptyStack());
    return arr[topEle-1];
}

template<class type>
void stackArr<type>::pop() {
    assert(!isEmptyStack());
    topEle--;
}


template<class type>
void stackArr<type>::copyStack(const stackArr<type> &otherStack) {
    delete [] arr;
    size=otherStack.size;
    topEle=otherStack.topEle;
    arr = new type[size];
    for(int i=0 ; i<size;i++)
        arr[i]=otherStack.arr[i];
}

template<class type>
const stackArr<type>& stackArr<type>::operator=(const stackArr<type> &otherStack) {
    copyStack(otherStack);
}

template<class type>
stackArr<type>::stackArr(const stackArr<type> &otherStack) {
    arr= nullptr;
    copyStack(otherStack);
}

template<class type>
stackArr<type>::stackArr(int stackSize) {
    size=stackSize;
    topEle=0;
    arr = new type[100];
}

template<class type>
stackArr<type>::~stackArr<type>() {
    delete [] arr;
}