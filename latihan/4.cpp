#include <iostream>
using namespace std;

typedef struct node *address;
struct node {
    address prev;
    int data;
    address next;
};

address first, last;

address alokasi(int datac) {
    address baru = new node;
    baru->prev = NULL;
    baru->next = NULL;
    baru->data = datac;
    return baru;
}

void insertfirst(address baru) {
    if (first != NULL) {
        baru->next = first;
        first->prev = baru;
        first = baru;
    } else {
        first = baru;
        last = baru;
    }
}

void insertlast(address baru) {
    if (first != NULL) {
        baru->prev = last;
        last->next = baru;
        last = baru;
    } else {
        first = baru;
        last = baru;
    }
}

void insertafter (address lama, address baru) {
    baru->next = lama->next;
    baru->prev = lama;
    lama->next = baru;
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
    insertfirst(alokasi(10));
    insertfirst(alokasi(20));
    insertfirst(alokasi(30));
    insertlast(alokasi(70));
    insertlast(alokasi(80));
    insertlast(alokasi(90));
    // insertafter(first, alokasi(40));
    // deletefirst();
    // deletelast();
    // deleteafter(first);
    cetak();

    return 0;
}