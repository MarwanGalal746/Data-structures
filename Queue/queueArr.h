//
// Created by marwan on 6/5/20.
//

#ifndef QUEUE8_QUEUEARR_H
#define QUEUE8_QUEUEARR_H

#include "queue.h"

template<class type>
class queueArr : public queue<type> {
public:
    const queueArr<type> &operator=(const queueArr<type> &);

    bool isEmptyQueue() const;

    bool isFullQueue() const;

    void initializeQueue();

    type front() const;

    type back() const;

    void addQueue(const type &queueElement);

    void deleteQueue();

    explicit queueArr(int queueSize = 100);

    queueArr(const queueArr<type> &otherQueue);

    ~queueArr();

private:
    void uticopy(const queueArr<type> &otherQueue);

    int maxQueueSize;
    int count;
    int queueFront;
    int queueRear;
    type *list;
};


#endif //QUEUE8_QUEUEARR_H