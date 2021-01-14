//
// Created by marwan on 6/6/20.
//

#ifndef HASHING9_HASHT_H
#define HASHING9_HASHT_H
#include <iostream>
using namespace std;
template<class type>
class hashT {
public:
    void insert(int hashIndex, const type &rec);

    bool isItemAtEqual(int hashIndex, const type &rec) const;

    void retrieve(int hashIndex, type &rec) const;

    void remove(int hashIndex, const type &rec);

    void print() const;

    explicit hashT(int size = 101);

    ~hashT();

private:
    void search(int &hashIndex, const type &rec, bool &found) const;
    type *HTable;
    int *indexStatusList;
    int length;
    int HTSize;
};


#endif //HASHING9_HASHT_H