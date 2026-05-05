#include <iostream>
using namespace std;

// Membuat sebutan address untuk lokasi memori
typedef struct node *address;

// Membuat kerangka data
// Menyimpan angka dan lokasi data sesudahnya
struct node {
    int data;
    address next;
};

// Membuat penanda untuk data urutan pertama
address first;

// Menyiapkan data baru dengan angka yang kita tentukan
// Lokasi pengait data sesudahnya masih kosong
address alokasi(int data) {
    address baru = new node;
    baru->data = data;
    baru->next = NULL;
    return baru;
}

// Menaruh data baru di urutan paling awal
void insertfirst(address baru) {
    baru->next = first;
    first = baru;
}

// Menaruh data baru di urutan paling akhir
// Program menelusuri data dari awal hingga akhir untuk memasang pengait
void insertlast(address baru) {
    if (first == NULL) {
        first = baru;
        return;
    }
    address tmp = first;
    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = baru;
}

// Menghapus data urutan paling awal dan membersihkan memori
void deletefirst() {
    if(first != NULL){
        address tmp = first;
        first = first->next;
        delete tmp;
    }
}

// Menghapus data urutan paling akhir dan membersihkan memori
// Program mencari data sebelum urutan terakhir untuk memutus sambungan
void deletelast() {
    if (first == NULL) {
        return;
    }
    
    if (first->next == NULL){
        delete first;
        first = NULL;
        return;
    }
    
    address tmp = first;
    while(tmp->next->next != NULL) {
        tmp = tmp->next;
    }
    
    delete tmp->next;
    tmp->next = NULL;
}

// Membaca setiap data dari urutan pertama sampai terakhir
// Menampilkan angka di dalam setiap data ke layar
void cetak (address baru) {
    while(baru != NULL){
        cout << "datanya " << baru->data << endl;
        baru = baru->next;
    }
}

int main() {
    // Memastikan penanda urutan pertama dalam keadaan kosong
    first = NULL;

    // Menambah angka 10 dan menjadikannya urutan pertama
    // Urutan: 10
    insertfirst(alokasi(10));
    
    // Menambah angka 31 dan menjadikannya urutan paling akhir
    // Urutan: 10, 31
    insertlast(alokasi(31));
    
    // Menambah angka 20 di depan angka 10
    // Urutan: 20, 10, 31
    insertfirst(alokasi(20));
    
    // Menambah angka 21 di belakang angka 31
    // Urutan: 20, 10, 31, 21
    insertlast(alokasi(21));
    
    // Menambah angka 30 di depan angka 20
    // Urutan: 30, 20, 10, 31, 21
    insertfirst(alokasi(30));
    
    // Menambah angka 11 di belakang angka 21
    // Urutan: 30, 20, 10, 31, 21, 11
    insertlast(alokasi(11));
    
    // Program memutus sambungan data urutan terakhir lalu menghapusnya
    // Urutan: 30, 20, 10, 31, 21
    deletelast();
    
    // Program memutus sambungan data urutan pertama lalu menghapusnya
    // Urutan: 20, 10, 31, 21
    deletefirst();
    
    // Menampilkan sisa urutan angka ke layar
    cetak(first);

    // Mengakhiri program
    return 0;
}