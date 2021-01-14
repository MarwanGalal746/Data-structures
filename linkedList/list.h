//
// Created by marwan on 6/15/20.
//

#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include <iostream>

using namespace std;

template<class type>
struct Node {
    type data;
    Node *next = NULL;
    Node *prev = NULL;
};

template<class type>
class list {
    Node<type> *first;
    Node<type> *last;
    Node<type> *end_ptr;//pointing to the dummy node
    int count;
public:
    class Iterator{
        Node<type> *cur;

    public:

        Iterator() {
            cur = NULL;
        }

        Iterator(Node<type> *ptr) {
            cur = ptr;
        }

        Iterator operator++(int) {
            Node<type> *n = cur;
            cur = cur->next;
            return Iterator(n);

        }

        Iterator operator++() {
            try {
                if (cur->next != NULL)
                    cur = cur->next;
                else
                    throw out_of_range("OUT OF RANGE, YOU ARE ALREADY IN THE END OF LIST\n");
            }
            catch (out_of_range &e) {
                cout << e.what();
            }
            return *this;
        }

        Iterator operator--(int) {
            Node<type> *n = cur;
            try {
                if (cur->prev != NULL) {
                    cur = cur->prev;
                    return Iterator(n);
                } else
                    throw out_of_range("OUT OF RANGE, YOU ARE ALREADY IN THE FIRST ELEMENT IN THE LIST\n");
            }
            catch (out_of_range &e) {
                cout << e.what();
            }
        }

        Iterator operator--() {
            try {
                if (cur->prev != NULL)
                    cur = cur->prev;
                else
                    throw out_of_range("OUT OF RANGE, YOU ARE ALREADY IN THE FIRST ELEMENT IN THE LIST\n");
            }
            catch (out_of_range &e) {
                cout << e.what();
            }
            return *this;
        }

        type &operator*() const {
            return cur->data;
        }

        bool operator==(const Iterator &second) const {
            return cur == second.cur;
        }

        bool operator!=(const Iterator &second) const {
            return (cur != second.cur);
        }
    };

    list();

    list(const type &val, const int &size);

    ~list();

    void destroy();

    list<type> &operator=(list<int> *second);

    int size();

    void insert(const type &val,Iterator itr);

    void insert2(const type &val);

    void print();

    typename list::Iterator erase(const Iterator &itr);

    Iterator begin(){
        Node<type>*x=first;
        Iterator itr(first);
        return itr;
    }


    Iterator end(){
        Iterator itr(nullptr);
        return itr;
    }
};


#endif //GRAPH_LIST_H