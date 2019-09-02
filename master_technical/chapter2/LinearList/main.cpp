#include <iostream>
#include "main.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    SeqList L;
    L.data = new ElemType[InitSize];
    L.length = InitSize;
    for(int i = 0 ; i < InitSize; i++) {
        L.data[i] = i;
    }
    printList(L);
    return 0;
}


void printList(SeqList &l) {
    for(int i = 0; i < l.length; i++) {
        cout << l.data[i] << " ";
    }
    cout << endl;
}
