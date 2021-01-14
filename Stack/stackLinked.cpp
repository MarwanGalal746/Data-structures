//
// Created by marwan on 6/1/20.
//

#include "stackLinked.h"
using namespace std;
template<class type>
void stackLinked<type>::initializeStack() {
    node *temp;
    while(topEle!= nullptr){
        temp=topEle;
        topEle=topEle->next;
        delete temp;
    }
    size=0;
}

template<class type>
stackLinked<type>::~stackLinked<type>() {
    initializeStack();
}

/*
template<class type>
void stackLinked<type>::copyStack(const stackLinked<type> &otherStack) {
    if(topEle!= nullptr)
        initializeStack();
    if(otherStack.topEle== nullptr)
        topEle= nullptr , size=0;
    else{
        topEle=new node;
        topEle->data=otherStack.topEle->data;
        topEle->next= nullptr;
        node*curr=topEle;
        node*temp = otherStack.topEle;
        temp=temp->next;
        size=otherStack.size;
        while(temp!= nullptr){
            node*New = new type;
            New->data=temp->data;
            New->next= nullptr;
            temp=temp->next;
            curr->next=New;
            curr=New;
        }
    }
}
*/

template<class type>
stackLinked<type>::stackLinked() {
    topEle= nullptr;
    size=0;
}

template<class type>
bool stackLinked<type>::isEmptyStack() const {
    return topEle== nullptr;
}

template<class type>
bool stackLinked<type>::isFullStack() const {
    return false;
}

template<class type>
void stackLinked<type>::push(const type &newItem) {
    node*newNode = new node;
    newNode->data=newItem;
    newNode->next=topEle;
    topEle=newNode;
    size++;
}

template<class type>
void stackLinked<type>::pop() {
    node*temp=topEle;
    topEle=topEle->next;
    delete temp;
    size--;
}

template<class type>
type stackLinked<type>::top() const {
    assert(topEle!= nullptr);
    return topEle->data;
}

template<class type>
stackLinked<type>::stackLinked(const stackLinked<type> &otherStack) {
    topEle= nullptr;
    copyStack(otherStack);
}

template<class type>
const stackLinked<type>& stackLinked<type>:: operator=(const stackLinked<type> &otherStack){
    copyStack(otherStack);
}

template<class type>
bool stackLinked<type>::operator==(const stackLinked<type> &other) {
    if(size!=other.size)
        return false;
    node* temp1 = topEle;
    node* temp2 = other.topEle;
    while(temp1!= nullptr){
        if(temp1->data!=temp2->data)
            return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
}


template<class type>
void stackLinked<type>::print() {
    node*temp = topEle;
    while(temp!= nullptr)
        cout<<temp->data , temp=temp->next;
}