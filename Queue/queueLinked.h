//
// Created by marwan on 6/5/20.
//

#ifndef QUEUE8_QUEUELINKED_H
#define QUEUE8_QUEUELINKED_H
#include "queue.h"

template<class type>
class queueLinked : public queue<type> {
public:
    const queueLinked<type>& operator=(const queueLinked<type>&);
    bool isEmptyQueue() const;
    bool isFullQueue() const;
    void initializeQueue();
    type front() const;
    type back() const;
    void addQueue(const type& queueElement);
    void deleteQueue();
    queueLinked();
    queueLinked(const queueLinked<type>& otherQueue);
    ~queueLinked();

private:
    struct node{
        type data;
        node* link;
    };
    node *queueFront;
    node *queueRear;
    int count;
    void uticopy(const queueLinked<type>& otherQueue);
};


#endif //QUEUE8_QUEUELINKED_H