//
// Created by marwan on 1/16/21.
//

#ifndef SUFFIXARRAY_SUFFIXARRAY_H
#define SUFFIXARRAY_SUFFIXARRAY_H


int *pos;

struct compareSuff {
    int tab;

    compareSuff(int tab) {
        this->tab = tab;
    }

    bool operator()(int fir, int sec) {
        if (pos[fir] != pos[sec])
            return pos[fir] < pos[sec];
        return pos[fir + tab] < pos[sec + tab];
    }
};

class SuffixArray {
private:
    int n;
    char *str;
    int *suff;
    int *sArr;
public:
    void utilityMergeSort(int l, int m, int r, compareSuff c);

    void mergeSort(int l, int r, compareSuff c);

    SuffixArray(char *arr);

    void ConstructUsingPrefixDoubling();

    void Print();
};


#endif //SUFFIXARRAY_SUFFIXARRAY_H
