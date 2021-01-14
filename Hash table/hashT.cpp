//
// Created by marwan on 6/6/20.
//

#include "hashT.h"

template<class type>
hashT<type>::hashT(int size) {
    HTable = new type[size];
    indexStatusList = new int[size];
    HTSize = size;
}

template<class type>
hashT<type>::~hashT() {
    delete[] HTable;
    delete[] indexStatusList;
}

/*template<class type>
int hashT<type>::hashFun(const string &s) {
    int sum = 0;
    for (int i = 0; i < s.length(); i++)
        sum += s[i];
    return sum % HTSize;
}*/

template<class type>
void hashT<type>::insert(int hashIndex, const type &rec) {
    int p = 0;
    int inc = 1;
    while (indexStatusList[hashIndex] == 1 && HTable[hashIndex] != rec && p < HTSize / 2) {
        hashIndex = (hashIndex + inc) % HTSize;
        inc += 2;
    }
    if (indexStatusList[hashIndex] != 1) {
        HTable[hashIndex] = rec;
        length++;
        indexStatusList[hashIndex] = 1;
    } else if (HTable[hashIndex] == rec)
        cerr << "dup value\n";
    else
        cerr << "full\n";
}

template<class type>
void hashT<type>::search(int &hashIndex, const type &rec, bool &found) const {
    int p = 0;
    int inc = 1;
    while (indexStatusList[hashIndex] == 1 && HTable[hashIndex] != rec && p < HTSize / 2) {
        hashIndex = (hashIndex + inc) % HTSize;
        inc += 2;
    }
    found = HTable[hashIndex] == rec && indexStatusList[hashIndex] == 1;
}

template<class type>
bool hashT<type>::isItemAtEqual(int hashIndex, const type &rec) const {
    return HTable[hashIndex] == rec;
}

template<class type>
void hashT<type>::retrieve(int hashIndex, type &rec) const {
    if (indexStatusList[hashIndex] == 1)
        rec = HTable[hashIndex];
}

template<class type>
void hashT<type>::remove(int hashIndex, const type &rec) {
    bool found;
    search(hashIndex, rec, found);
    if (found)
        indexStatusList[hashIndex] = -1, length--;
    else
        cerr << "not found\n";
}