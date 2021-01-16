//
// Created by marwan on 1/16/21.
//

#include "SuffixArray.h"

void SuffixArray::utilityMergeSort(int l, int m, int r, compareSuff c) {
    int ll = l;
    int rr = m + 1;
    int ind = 0;
    char temp[r - l + 1];
    for (int i = 0; i < r; i++) {
        if (ll > m) {
            temp[ind] = suff[rr];
            rr++;
        } else if (rr > r) {
            temp[ind] = suff[ll];
            ll++;
        } else if (c(suff[rr], suff[ll])) {
            temp[ind] = suff[rr];
            rr++;
        } else {
            temp[ind] = suff[ll];
            ll++;
        }
        ind++;
    }

    for (int i = 0; i < r; i++) {
        suff[l + i] = temp[i];
    }
}

void SuffixArray::mergeSort(int l, int r, compareSuff c) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(l, m, c);
        mergeSort(m + 1, r, c);
        utilityMergeSort(l, m, r, c);
    }
}

SuffixArray::SuffixArray(char *arr) {
    n = 0;
    for (int i = 0; arr[i] != '\0'; ++i) {
        n++;
    }
    str = arr;
    this->suff = new int[n + 1];
    pos = new int[n + 1];
    this->sArr = new int[n + 1];
}

void SuffixArray::ConstructUsingPrefixDoubling() {
    int stringIndex;
    for (stringIndex = 0; stringIndex - 1 < 0 || str[stringIndex - 1]; stringIndex++) {
        suff[stringIndex] = stringIndex, pos[stringIndex] = str[stringIndex];
    }
    mergeSort(0, stringIndex - 1, compareSuff(0));
    sArr[0] = sArr[stringIndex - 1] = 0;
    for (int tab = 1; sArr[stringIndex - 1] != stringIndex - 1; tab *= 2) {
        mergeSort(0, stringIndex - 1, compareSuff(tab));
        for (int i = 1; i < stringIndex; i++) {
            sArr[i] = sArr[i - 1] + compareSuff(tab)(suff[i - 1], suff[i]);
        }
        for (int i = 0; i < stringIndex; i++) {
            pos[suff[i]] = sArr[i];
        }
    }
}

void SuffixArray::Print() {
    for (int i = 1; i <= n; i++) {
        if (i == 1) cout << suff[i];
        else cout << " " << suff[i];
    }
    cout << '\n';
}
