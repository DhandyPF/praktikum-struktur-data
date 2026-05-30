#include <iostream>
#include <string>
using namespace std;

typedef struct node *address;
struct node{
    string data;
    address next;
};

typedef struct {
    address front;
    address rear;
} Queue;

Queue antrian;

void init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

address alokasi(string nama) {
    address databaru = new node;
    databaru->data = nama;
    databaru->next = NULL;
    return databaru;
}

bool isEmpty(Queue *q){
    return (q->front == NULL); 
}

void enqueue(Queue *q, string nama) {
    address databaru = alokasi(nama);
    if (isEmpty(q)){
        q->front = databaru;
        q->rear = databaru;
    } else {
        q->rear->next = databaru;
        q->rear = databaru;
    }
}

void cetak(Queue *q, string nama) {
    if (isEmpty(q)) {
        cout << "Antrian masih kosong.\n";
    } else {
        address antri = q->front;
        while (antri != NULL) {
            cout << antri->data << " ";
            antri = antri->next;
        } cout << "\n";
    }
}

int main() {
    init(&antrian);
    enqueue(&antrian, "dimas");
    cetak(&antrian);

    return 0;
}