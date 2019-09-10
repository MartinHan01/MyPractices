#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define InitSize 30
#define ElemType int

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

void InitList(SeqList &l);
void printList(SeqList &l);
bool ListInsert(SeqList &L, int i, ElemType e);
bool ListDelete(SeqList &L, int i, ElemType &e);
int LocateElem(SeqList &L, ElemType e);
ElemType deleteMin(SeqList &L);
void reverseList(SeqList &L);
void deleteListItem(SeqList &L);
void deleteItem(SeqList &L, ElemType e);
void deleteItemIn(SeqList &L, ElemType startNum, ElemType endNum);

#endif // MAIN_H_INCLUDED
