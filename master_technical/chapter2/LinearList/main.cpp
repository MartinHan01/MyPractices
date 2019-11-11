#include <iostream>
#include "main.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    SeqList L;
    InitList(L);
    printList(L);
    ListInsert(L, 2, 10);
    printList(L);
    ElemType del;
    ListDelete(L , 2, del);
    cout << "del:" << del << endl;
    printList(L);
    cout << "Elem 3 locate:" << LocateElem(L, 3) << endl;
    cout << "deleteMin value" << endl;
    ElemType minVal = deleteMin(L);
    cout << "minVal is " << minVal << endl;
    printList(L);
    cout << "reverse List" << endl;
    reverseList(L);
    printList(L);
    int deleteVal = 3;
    cout << "delete Item " << deleteVal << endl;
    deleteItem(L, deleteVal);
    printList(L);
    cout << "sort list" << endl;
    sortList(L);
    printList(L);
    int minValInt = 5,maxValInt = 8;
    cout << "delete Item in " << minValInt << "," << maxValInt << endl;
    deleteItemIn(L, minValInt, maxValInt);
    printList(L);
    cout << "Init List" << endl;
    SeqList L1;
    InitList2(L1);
    printList(L1);
    deleteDuplicate(L1);
    printList(L1);
    cout << "merge list" << endl;
    sortList(L);
    sortList(L1);
    cout << "L L1 is " << endl;
    printList(L);
    printList(L1);
    SeqList L2;
    mergeList(L, L1, L2);
    printList(L2);
    return 0;
}
void InitList(SeqList &l) {
    l.data = new ElemType[InitSize];
    int length = 10;
    l.length = length;
    for(int i = 0 ; i < length; i++) {
        l.data[i] = i;
    }
}

void InitList2(SeqList &l) {
    l.data = new ElemType[InitSize];
    int length = 30;
    l.length = length;
    for(int i = 0 ; i < length; i++) {
        l.data[i] = i % 6;
    }
}

void InitListBySize(SeqList &l, int size) {
    l.data = new ElemType[size];
    int length = size;
    l.length = length;
    for(int i = 0 ; i < length; i++) {
        l.data[i] = 0;
    }
}

void printList(SeqList &l) {
    for(int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}

bool ListInsert(SeqList &L, int i, ElemType e) { // O(n)
    if(i < 1 || i > L.length + 1) {
        return false;
    }
    if(L.length >= L.MaxSize) {
        return false;
    }
    for(int j = L.length; j >= i; j--) {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

bool ListDelete(SeqList &L, int i, ElemType &e) {
    if(i < 1 || i > L.length + 1) {
        return false;
    }
    e = L.data[i - 1];
    for(int j = i; j < L.length; j++) {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
int LocateElem(SeqList &L, ElemType e) {
    int i;
    for(i = 0 ; i < L.length; i++) {
        if(L.data[i] == e) {
            return i + 1;
        }
    }
    return 0;
}
ElemType deleteMin(SeqList &L) {
    if(L.length == 0) {
        return NULL;
    }
    ElemType minVal = L.data[0];
    int index = 0;
    for(int i = 1 ; i < L.length; i++) {
        if(L.data[i] < minVal) {
            minVal = L.data[i];
            index = i;
        }
    }
    for(int i = index; i< L.length - 1; i++) {
        L.data[i] = L.data[i + 1];
    }
    L.length--;
    return minVal;
}

void reverseList(SeqList &L) {
    if(L.length == 0) {
        return ;
    }
    int tmp;

    for(int i = 0 ; i < L.length / 2; i++) {
        tmp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = tmp;
    }
}

void deleteListItem(SeqList &L) {
    if(L.length == 0) {
        return ;
    }
}

void deleteItem(SeqList &L, ElemType e) {
    int fixLength = L.length;
    for(int i = 0; i < fixLength; i++) {
        ElemType item = L.data[i];
        if(item == e) {
            for(int j = i; j < fixLength - 1; j++) {
                L.data[j] = L.data[j + 1];
            }
            fixLength--;
            L.length--;
        }

    }
}

void deleteItemIn(SeqList &L, ElemType startNum, ElemType endNum) {
    if(startNum > endNum) {
        return ;
    }
    int startIndex = -1, endIndex = -1;
    int middleLen = -1;
    for(int i = 0 ; i < L.length;i++) {
        if(L.data[i] >= startNum && startIndex == -1) {
            startIndex = i;
        }
        if(L.data[i] > endNum && endIndex == -1) {
            endIndex = i;
            middleLen = endIndex - startIndex;
        }
        if(startIndex != -1 && endIndex != -1) {
            L.data[i - middleLen] = L.data[i];
        }
    }
    L.length = L.length - middleLen;
}

void quickSortList(SeqList &L, int startIndex, int endIndex) {
    if(startIndex >= endIndex) {
        return ;
    }
    int i = startIndex, j = endIndex, s = L.data[startIndex];
    while(i < j) {
        while(i < j && L.data[j] > s) {
            j--;
        }
        if(i < j) {
            L.data[i++] = L.data[j];
        }
        while(i < j && L.data[i] < s) {
            i++;
        }
        if(i < j) {
            L.data[j--] = L.data[i];
        }
    }
    L.data[i] = s;
    quickSortList(L, startIndex, i);
    quickSortList(L, i + 1, endIndex);
}

void sortList(SeqList &L) {
    int startIndex = 0;
    int endIndex = L.length - 1;
    quickSortList(L,startIndex, endIndex);
}

//´ÓºóÍùÇ°É¾
void deleteDuplicate(SeqList &L) {
    for(int i = L.length - 1; i > 0 ; i--) {
        ElemType item = L.data[i];
        for(int j = i - 1; j >= 0; j--) {
            if(item == L.data[j]) {
                for(int k = j; k < L.length - 1; k++) {
                    L.data[k] = L.data[k + 1];
                }
                L.length--;
                i--;
            }
        }
    }
}

void mergeList(SeqList &L1, SeqList &L2,SeqList &L3) {
    int length = L1.length + L2.length;
    int finished = 0;
    InitListBySize(L3, length);
    for(int i = 0,j = 0 ; finished <= length - 1 ;) {
        if(i > L1.length - 1) {
            L3.data[finished] = L2.data[j];
            j++;
        } else if(j > L2.length - 1) {
            L3.data[finished] = L1.data[i];
            i++;
        } else if(L1.data[i] > L2.data[j]) {
            L3.data[finished] = L2.data[j];
            j++;
        } else {
            L3.data[finished] = L1.data[i];
            i++;
        }
        finished++;
    }


}
