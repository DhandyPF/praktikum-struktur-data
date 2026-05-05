#include <iostream>
using namespace std;

// Membuat sebutan address untuk lokasi memori
typedef struct node *address;

// Membuat kerangka data
// Menyimpan angka dan lokasi data sesudahnya
// Single linked list tidak memiliki lokasi data sebelumnya
struct node {
    int data;
    address next;
};

// Membuat penanda untuk data urutan pertama dan terakhir
address first, last;

// Menyiapkan data baru dengan angka yang kita tentukan
// Lokasi pengait data sesudahnya masih kosong
address alokasikan (int data_x) {
    address x = new node;
    x->next = NULL;
    x->data = data_x;
    return x;
}

// Menaruh data baru di urutan paling awal
// Jika belum ada data program menjadikannya yang pertama dan terakhir
// Jika sudah ada data program menggeser data lama ke urutan kedua
void insertFirst (address baru) {
    if (first != NULL) {
        baru->next = first;
        first = baru;
    } else {
        first = baru;
        last = baru;
    }
}

// Menaruh data baru di urutan paling akhir
// Program menyambungkan data baru di belakang data terakhir yang sudah ada
void insertLast (address baru) {    
    if (first != NULL) {
        last->next = baru;
        last = baru;
    } else {
        first = baru;
        last = baru;
    }
}

// Menyisipkan data baru di antara dua data
// Program menempatkan data baru tepat setelah data lama yang kita pilih
void insertAfter(address lama, address baru) {
    baru->next = lama->next;
    lama->next = baru;
}

// Menghapus data urutan paling awal
// Program memajukan data urutan kedua menjadi data urutan pertama
void deleteFirst() {
    if (first != NULL) {
        address tmp = first;
        first = first->next;
        delete(tmp);
    }
}

// Menghapus data urutan paling akhir
// Program mencari data sebelum urutan terakhir untuk memutus sambungan
void deleteLast() {
    if (first != NULL) {
        if (first == last) {
            delete(first);
            first = NULL;
            last = NULL;
        } else {
            address jalan = first;
            while (jalan->next != last) {
                jalan = jalan->next;
            }
            address tmp = last;
            last = jalan;
            last->next = NULL;
            delete(tmp);
        }
    }
}

// Menghapus satu data yang posisinya tepat setelah data yang kita pilih
void deleteAfter(address lama) {
    if (lama != NULL && lama->next != NULL) {
        address tmp = lama->next;
        lama->next = tmp->next;
        delete(tmp);
    }
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
    // Mengosongkan penanda urutan pertama dan terakhir
    first = NULL;
    last = NULL;
    
    // Menambah angka 10 dan menjadikannya urutan pertama
    insertFirst(alokasikan(10));
    // Menambah angka 30 di depan angka 10
    insertFirst(alokasikan(30));
    // Menambah angka 50 di depan angka 30
    insertFirst(alokasikan(50));
    
    // Menambah angka 70 dan menjadikannya urutan paling akhir
    insertLast(alokasikan(70));
    // Menambah angka 80 di belakang angka 70
    insertLast(alokasikan(80));
    // Menambah angka 90 di belakang angka 80
    insertLast(alokasikan(90));
    
    // Program memutus sambungan data pada urutan ketiga dari list lalu menghapus memori data tersebut
    // Menghapus angka 10 yang posisinya tepat setelah urutan kedua
    deleteAfter(first->next);
    
    // Menampilkan sisa urutan angka ke layar
    cetak();

    // Mengakhiri program
    return 0;
}