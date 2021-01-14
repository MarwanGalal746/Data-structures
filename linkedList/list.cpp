//
// Created by marwan on 6/15/20.
//

#include "list.h"


template<class type>
list<type>::list() {
    count = 0;
    Node<type> *dummy = new Node<type>;
    end_ptr = nullptr;
    first = nullptr;
    last = nullptr;
}

template<class type>
list<type>::list(const type &val, const int &size) {
    end_ptr = nullptr;
    first = nullptr;
    last = nullptr;
    count = 0;
    for (int i = 0; i < size; i++) {
        if (i == 0)
            last = first;
        insert(val, begin());
    }
}

template<class type>
list<type>::~list() {
    destroy();
}

template<class type>
void list<type>::destroy() {
    Node<type> *cur = first;
    while (cur != end_ptr) {
        Node<type> *temp = cur;
        cur = cur->next;
        cur->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
}

template<class type>
list<type> &list<type>::operator=(list<int> *second) {
    if (&second != this) {
        if(first!= nullptr)
            this->~list<type>();
        Node<type> *temp;
        temp = second->first;
        while (temp->next != NULL) {
            insert(temp->data, Iterator(end_ptr));
            temp = temp->next;
        }
        delete temp;
    }
    return *this;
}

template<class type>
int list<type>::size() {
    return count;
}

template<class type>
void list<type>::insert2(const type &val) {
    if(count==0)
        first=last= nullptr;
    Node<type>* newNode = new Node<type>;
    newNode->data=val;
    newNode->next= nullptr;
    if(first== nullptr)
        first=last=newNode , newNode->prev= nullptr;
    else{
        Node<type>*x=first;
        last->next=newNode;
        newNode->prev=last;
        last=newNode;
    }
}

template<class type>
void list<type>::print() {
    Node<type> *ptr;
    ptr = first;
    while (ptr != end_ptr) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}


template<class type>
typename list<type>::Iterator list<type>::erase(const list::Iterator &itr) {
    count--;
    Node<type> *targetNode = first;
    if (Iterator(first) == itr) {
        Node<type> *temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
        Iterator resItr(first);
        return resItr;
    } else {
        targetNode = targetNode->next;
        Node<type> *prevNode = first;
        while (Iterator(targetNode) != itr) {
            prevNode = targetNode;
            targetNode = targetNode->next;
        }
        Node<type> *temp = targetNode;
        prevNode->next = targetNode->next;
        targetNode->next->prev = prevNode;
        delete temp;
        return Iterator(prevNode->next);
    }
}

/*template<class type>
typename list<type>::Iterator list<type>::begin() {
    Iterator itr(first);
    return itr;
}

template<class type>
typename list<type>::Iterator list<type>::end() {
    Iterator itr(end_ptr);
    return itr;
}*/

template<class type>
void list<type>::insert(const type &val,Iterator itr) {
    Node<type>* newNode;
    newNode = new Node<type>;
    if (count == 0)
    {
        newNode->data = val;
        newNode->next = end_ptr;
        newNode->prev = NULL;
        first = newNode;
        last = newNode;
    }
    else if (itr == Iterator(first))
    {
        newNode->data = val;
        first->prev = newNode;
        newNode->next = first;
        newNode->prev = NULL;
        first = newNode;
    }
    else if(itr == Iterator(end_ptr))
    {
        newNode->data = val;
        newNode->prev = last;
        newNode->next = end_ptr;
        last->next = newNode;
        last=newNode;
    }
    else
    {

        Node<type>*curNode=first->next;
        Node<type>*preNode=first;
        Iterator curItr(curNode);

        while(curItr!=itr){
            preNode=curNode;
            curNode=curNode->next;
        }
        newNode->data = val;
        preNode->next=newNode;
        newNode->prev=preNode;
        newNode->next=curNode;
        curNode->prev=newNode;
    }
    count++;
}
