#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define InitSize 30
#define ElemType int

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

void InitList(SeqList &l);
void InitList2(SeqList &l);
void printList(SeqList &l);
bool ListInsert(SeqList &L, int i, ElemType e);
bool ListDelete(SeqList &L, int i, ElemType &e);
int LocateElem(SeqList &L, ElemType e);
ElemType deleteMin(SeqList &L);
void reverseList(SeqList &L);
void deleteListItem(SeqList &L);
void deleteItem(SeqList &L, ElemType e);
void deleteItemIn(SeqList &L, ElemType startNum, ElemType endNum);
void sortList(SeqList &L);
void quickSortList(SeqList &L, int startIndex, int endIndex);
void deleteDuplicate(SeqList &L);
void mergeList(SeqList &L1, SeqList &L2,SeqList &L3);
void InitListBySize(SeqList &l, int size);
#endif // MAIN_H_INCLUDED
