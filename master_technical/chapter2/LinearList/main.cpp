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
