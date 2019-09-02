#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#define InitSize 100
#define ElemType int

typedef struct {
    ElemType *data;
    int MaxSize, length;
} SeqList;

void InitList(SeqList &l);
void printList(SeqList &l);



#endif // MAIN_H_INCLUDED
