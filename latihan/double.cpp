#include <iostream>
using namespace std;

// Membuat sebutan address untuk lokasi memori
typedef struct node *address;

// Membuat kerangka data
// Menyimpan angka dan lokasi data sebelum serta sesudahnya
struct node {
    address prev;
    int data;
    address next;
};

// Membuat penanda untuk data urutan pertama dan terakhir
address first, last;

// Menyiapkan data baru dengan angka yang kita tentukan
// Lokasi data sebelum dan sesudahnya masih kosong
address alokasi (int data_baru) {
    address baru = new node;
    baru->prev = NULL;
    baru->next = NULL;
    baru->data = data_baru;
    return baru;
}

// Menaruh data baru di urutan paling awal
// Jika belum ada data program menjadikannya yang pertama dan terakhir
// Jika sudah ada data program menggeser data lama ke urutan kedua
void insertfirst(address baru) {
    if(first != NULL) {
        first->prev = baru;
        baru->next = first;
        first = baru;
    } else {
        first = baru;
        last = baru;
    }
}

// Menaruh data baru di urutan paling akhir
// Program menyambungkan data baru di belakang data terakhir yang sudah ada
void insertlast(address baru) {
    if(first != NULL) {
        last->next = baru;
        baru->prev = last;
        last = baru;
    } else {
        last = baru;
        first = baru;
    }
}

// Menyisipkan data baru di antara dua data
// Program menempatkan data baru tepat setelah data lama yang kita pilih
void insertafter(address lama, address baru) {
    baru->next = lama->next;
    baru->prev = lama;
    lama->next = baru;
    baru->next->prev = baru;
}

// Menghapus data urutan paling awal
// Program memajukan data urutan kedua menjadi data urutan pertama
void deletefirst() {
    address tmp = first;
    first = first->next;
    first->prev = NULL;
    delete(tmp);
}

// Menghapus data urutan paling akhir
// Program menjadikan data sebelumnya sebagai data urutan terakhir
void deletelast() {
    address tmp = last;
    last = last->prev;
    last->next = NULL;
    delete(tmp);
}

// Menghapus satu data yang posisinya tepat setelah data yang kita pilih
void deleteafter(address lama) {
    address tmp = lama->next;
    lama->next = tmp->next;
    delete(tmp);
}

// Membaca setiap data dari urutan pertama sampai terakhir
// Menampilkan angka di dalam setiap data ke layar
void cetak() {
    address jalan = first;
    while (jalan != NULL) {
        cout << jalan->data << endl;
        jalan = jalan->next;
    }
}

int main() {
    // Menambah angka 10 dan menjadikannya urutan pertama
    insertfirst(alokasi(10));

    // Menambah angka 20 di depan angka 10
    insertfirst(alokasi(20));

    // Menambah angka 30 di depan angka 20
    insertfirst(alokasi(30));

    // Menambah angka 40 dan menjadikannya urutan paling akhir
    insertlast(alokasi(40));

    // Menambah angka 50 di belakang angka 40
    insertlast(alokasi(50));

    // Menambah angka 60 di belakang angka 50
    insertlast(alokasi(60));

    // Menyisipkan angka 70 tepat setelah angka 30
    insertafter(first, alokasi(70));

    // Menyisipkan angka 80 tepat setelah angka 70
    insertafter(first->next, alokasi(80));

    // Menyisipkan angka 90 tepat setelah angka 80
    insertafter(first->next->next, alokasi(90));

    // Program memutus sambungan data urutan pertama dari list lalu menghapus memori data tersebut
    // Menghapus angka 30 yang berada di urutan pertama
    deletefirst();

    // Program memutus sambungan data urutan terakhir dari list lalu menghapus memori data tersebut
    // Menghapus angka 60 yang berada di urutan terakhir
    deletelast();

    // Program memutus sambungan data pada urutan kedua dari list lalu menghapus memori data tersebut
    // Menghapus angka 70 yang posisinya tepat setelah urutan pertama
    deleteafter(first);

    // Menampilkan sisa urutan angka ke layar
    cetak();

    // Mengakhiri program
    return 0;
}