#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    address prev;
    int data;
    address next;
};

address first, last;

address alokasi(int data) {
    address baru = new node;
    baru->data = data;
    baru->next = NULL;
    return baru;
}

void insertfirst(address baru){
    address baru;
    first->next = baru;
    first = baru;
}

void cetak(address baru) {
    while (baru != NULL) {
        cout << baru->data << endl;
        baru = baru->next;
    }
}

int main() {
    insertfirst(alokasi(10));

    return 0;
}