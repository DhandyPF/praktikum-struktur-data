#include <iostream>
#include <string>
using namespace std;

#define MAXSTACK 100

// -- STACK --

typedef struct {
    int item[MAXSTACK];
    int count;
} Stack;

Stack tumpukan;

bool isFull(Stack *x) {
    if ((x->count) >= MAXSTACK) {
        return true;
        return false;
    }
}

bool isEmpty(Stack *x) {
    if ((x->count) == 0) {
        return true;
    }
    return false;
}

void membuatStack(Stack *x) {
    x->count = 0;
}

// -- STACK --

// -- QUEUE --

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
// -- QUEUE --

// -- MENU --

void menu() {
    cout << "\n========================================\n";
    cout << "    SISTEM LAYANAN KLINIK SEHAT         \n";
    cout << "========================================\n";
    cout << "1. Daftar Pasien Baru (Antrian)\n";
    cout << "2. Panggil Pasien Selanjutnya\n";
    cout << "3. Tampilkan Antrian Pasien Saat Ini\n";
    cout << "4. Tampilkan Riwayat Pemeriksaan\n";
    cout << "5. Keluar\n";
    cout << "========================================\n";
    cout << "Pilih menu (1-5): ";
}

// -- MENU --

int main() {
    init(&antrian);
    menu();
    // enqueue(&antrian, "dimas");
    // cetak(&antrian);

    return 0;
}