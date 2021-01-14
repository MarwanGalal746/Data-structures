//
// Created by marwan on 6/5/20.
//

#include "queueArr.h"

template<class type>
bool queueArr<type>::isEmptyQueue() const {
    return !count;
}

template<class type>
bool queueArr<type>::isFullQueue() const {
    if (count == maxQueueSize) return true;
    return false;
}

template<class type>
void queueArr<type>::initializeQueue() {
    queueFront = count = 0;
    queueRear = maxQueueSize - 1;
}

template<class type>
type queueArr<type>::front() const {
    assert(!isEmptyQueue());
    return list[queueFront];
}

template<class type>
type queueArr<type>::back() const {
    assert(!isEmptyQueue());
    return list[queueRear];
}

template<class type>
void queueArr<type>::addQueue(const type &queueElement) {
    if (!isEmptyQueue()) {
        queueRear = (queueRear + 1) % maxQueueSize;
        list[queueRear] = queueElement;
        count++;
    }
}

template<class type>
void queueArr<type>::deleteQueue() {
    if (!isEmptyQueue()) {
        queueFront = (queueFront + 1) % maxQueueSize;
        count--;
    }
}

template<class type>
queueArr<type>::queueArr(const int queueSize) {
    if (queueSize > 0)
        list = new type[maxQueueSize], maxQueueSize = queueSize;
    initializeQueue();
}

template<class type>
queueArr<type>::~queueArr() {
    delete[] list;
}

template<class type>
void queueArr<type>::uticopy(const queueArr<type> &otherQueue) {
    ~queueArr<type>();
    initializeQueue();
    maxQueueSize = otherQueue.maxQueueSize;
    list = new type[maxQueueSize];
    count = 0;
    queueFront = 0;
    queueRear = otherQueue.count - 1;
    if (otherQueue.queueRear >= otherQueue.queueFront) {
        int ind = otherQueue.queueFront;
        for (int i = queueFront; i <= queueRear; i++)
            list[count++] = otherQueue.list[ind++];
    } else {
        int ind = otherQueue.queueFront;
        for (int i = queueFront; ind < otherQueue.maxQueueSize; i++)
            list[count++] = otherQueue.list[ind++];
        for (int i = 0; count < otherQueue.count; i++)
            list[count++] = otherQueue.list[i];
    }
}

template<class type>
const queueArr<type>&queueArr<type>::operator=(const queueArr<type> &otherQueue) {
    uticopy(otherQueue);
}

template<class type>
queueArr<type>::queueArr(const queueArr<type> &otherQueue) {
    uticopy(otherQueue);
}