//
// Created by marwan on 6/5/20.
//

#include "queueLinked.h"

template<class type>
bool queueLinked<type>::isEmptyQueue() const {
    return queueFront == nullptr;
}

template<class type>
bool queueLinked<type>::isFullQueue() const {
    return false;
}

template<class type>
queueLinked<type>::~queueLinked() {
    while (queueFront != nullptr) {
        node *temp = queueFront;
        queueFront = queueFront->link;
        delete temp;
    }
    initializeQueue();
}

template<class type>
void queueLinked<type>::initializeQueue() {
    ~queueLinked<type>();
    queueFront = queueRear = nullptr;
    count = 0;
}

template<class type>
type queueLinked<type>::front() const {
    assert(!isEmptyQueue());
    return queueFront->data;
}

template<class type>
type queueLinked<type>::back() const {
    assert(!isEmptyQueue());
    return queueRear->link;
}

template<class type>
void queueLinked<type>::addQueue(const type &queueElement) {
    node *newNode = new node;
    newNode->data = queueElement;
    newNode->link = nullptr;
    if (queueFront == nullptr)
        queueFront = queueRear = newNode;
    else
        queueRear->link = newNode, queueRear = queueRear->link;
}

template<class type>
void queueLinked<type>::deleteQueue() {
    if (queueFront != nullptr) {
        node* newNode = queueFront;
        queueFront=queueFront->link;
        delete newNode;
    }
}

template<class type>
queueLinked<type>::queueLinked() {
    queueFront=queueRear= nullptr;
    count=0;
}

template<class type>
queueLinked<type>::queueLinked(const queueLinked<type> &otherQueue) {
    initializeQueue();
    uticopy(otherQueue);
}

template<class type>
const queueLinked<type>&queueLinked<type>::operator=(const queueLinked<type> &otherQueue) {
    initializeQueue();
    uticopy(otherQueue);
}

template<class type>
void queueLinked<type>::uticopy(const queueLinked<type> &otherQueue) {
    if(otherQueue!=*this){
        initializeQueue();
        node* temp = otherQueue.queueFront;
        while(temp!= nullptr){
            node* newNode = new node;
            newNode->data=temp->data;
            newNode->link= nullptr;
            count++;
            queueRear=newNode;
            if(queueFront== nullptr)
                queueFront=newNode;
        }
    }
}