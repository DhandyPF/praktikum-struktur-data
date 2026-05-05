#include <iostream>
using namespace std;

typedef struct node *address;
struct node{
    address prev;
    int data;
    address next;
};

address first, last;

address alokasi(int datax) {
    address baru = new node;
    baru->data = datax;
    baru->next = NULL;
    baru->prev = NULL;
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
        first = NULL;
        last = NULL;
    }
}

void insertafter(address lama, address baru) {
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
    insertlast(alokasi(40));
    insertlast(alokasi(50));
    insertlast(alokasi(60));
    insertafter(first, alokasi(70));
    insertafter(first->next, alokasi(80));
    insertafter(first->next->next, alokasi(90));
    deletefirst();
    deletelast();
    deleteafter(first->next);
    cetak();

    return 0;
}