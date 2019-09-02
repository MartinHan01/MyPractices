#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    SeqList L;
    InitList(L);
    printList(L);
    return 0;
}
void InitList(SeqList &l) {
    l.data = new ElemType[InitSize];
    l.length = InitSize;
    for(int i = 0 ; i < InitSize; i++) {
        l.data[i] = i;
    }
}

void printList(SeqList &l) {
    for(int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}
