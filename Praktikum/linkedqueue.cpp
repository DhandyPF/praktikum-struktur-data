#include <iostream>
using namespace std;

// Deklarasi Node untuk Linked List
typedef struct tnode *address;
struct tnode {
    int data;
    address next;
};

// Deklarasi Struktur Queue yang menampung front dan rear
typedef struct {
    address front;
    address rear;
} Queue;

Queue antrian;

void init(Queue *q) {
    q->front = NULL;
    q->rear = NULL;
}

address alokasikan(int nilai) {
    address baru = new tnode;
    baru->data = nilai;
    baru->next = NULL;
    return baru;
}

bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

void enqueue(Queue *q, int nilai) {
    address baru = alokasikan(nilai);
    
    if (isEmpty(q)) {
        q->front = baru;
        q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }
    cout << nilai << " berhasil dimasukkan ke antrian.\n";
}

void dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong, tidak ada data yang diambil.\n";
    } else {
        address hapus = q->front;
        cout << hapus->data << " dikeluarkan dari antrian.\n";
        q->front = q->front->next;
        
        if (q->front == NULL) {
            q->rear = NULL;
        }
        delete hapus;
    }
}

void cetak(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
    } else {
        address jalan = q->front;
        cout << "Isi antrian (depan -> belakang): ";
        while (jalan != NULL) {
            cout << jalan->data << " ";
            jalan = jalan->next;
        }
        cout << "\n";
    }
}

int main() {
    init(&antrian);
    cout << "--- Simulasi Queue dengan Linked List ---\n";
    enqueue(&antrian, 10);
    enqueue(&antrian, 20);
    enqueue(&antrian, 30);
    cetak(&antrian);

    dequeue(&antrian);
    // dequeue(&antrian);
    // dequeue(&antrian);

    // enqueue(&antrian, 10);
    cetak(&antrian);
    
    return 0;
}