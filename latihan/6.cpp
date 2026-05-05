#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    address prev;
    int data;
    address next;
};

address first, last;

address alokasi(int datae) {
    address baru = new node;
    baru->prev = NULL;
    baru->data = datae;
    baru->next = NULL;
    return baru;
}

void insertfirst(address baru) {
    if (first != NULL) {
        first->prev = baru;
        baru->next = first;
        first = baru;
    } else {
        first = baru;
        last = baru;
    }
}

void insertlast(address baru) {
    if (first != NULL) {
        last->next = baru;
        baru->prev = last;
        last = baru;
    } else {
        first = baru;
        last = baru;
    }
}

void insertafter(address lama, address baru) {
    baru->next = lama->next;
    baru->prev = lama;
    baru->prev->next = baru;
}

void deletefirst() {
    address tmp = first;
    first = first->next;
    first->prev = NULL;
    delete(tmp);
}

void deletelast() {
    address tmp = last;
    last = last->prev;
    last->next = NULL;
    delete(tmp);
}

void deleteafter(address lama) {
    address tmp = lama->next;
    lama->next = tmp->next;
    delete(tmp);
}

void cetak() {
    address jalan = first;
    while (jalan != NULL) {
        cout << jalan->data << endl;
        jalan = jalan->next;
    }
    
}

int main() {
    insertlast(alokasi(30));
    insertlast(alokasi(40));
    insertfirst(alokasi(10));
    insertfirst(alokasi(20));
    insertafter(first, alokasi(50));
    insertafter(first->next, alokasi(60));
    deletefirst();
    deletelast();
    deleteafter(first->next);
    cetak();

    return 0;
}
