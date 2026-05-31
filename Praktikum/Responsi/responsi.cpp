#include <iostream>
#include <string>
using namespace std;

#define MAXSTACK 100
#define MAX_Q 100

// -- STACK --

typedef struct {
    string item[MAXSTACK];
    int count;
} Stack;

Stack riwayat;

bool isFull(Stack *x) {
    if ((x->count) >= MAXSTACK) {
        return true;
    }
    return false;
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

void push(string data, Stack *x) {
    if (isFull(x)) {
        cout << "Riwayat penuh \n";
    } else {
        x->item[x->count] = data;
        ++(x->count);
        cout << "Berhasil dimasukkan ke riwayat \n";
    }
}

void pop(Stack *x) {
    if (isEmpty(x)) {
        cout << "Tidak ada riwayat \n";
    } else {
        --(x->count);
        cout << "Data \"" << x->item[x->count] << "\" dihapus dari riwayat.\n";
    }
}

void cetakRiwayat(Stack *x) {
    if (isEmpty(x)) {
        cout << "Belum ada riwayat pasien\n";
        return;
    }
    for (int i = x->count - 1; i >= 0; i--) {
        cout << (x->count - i) << ". " << x->item[i] << endl;
    }
    cout << "Total pasien yang sudah diperiksa : " << x->count << endl;
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
    if (isEmpty(q)) {
        q->front = databaru;
        q->rear = databaru;
    } else {
        q->rear->next = databaru;
        q->rear = databaru;
    }

    cout << "Pasien atas nama \"" << nama << "\" berhasil didaftarkan ke antrian.\n";
}

string dequeue(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian kosong.\n";
        return "";
    }

    address hapus = q->front;
    string nilai = hapus->data;
    q->front = q->front->next;
    
    if (q->front == NULL) {
        q->rear = NULL;
    }

    delete hapus;
    return nilai;

}

void cetakAntrian(Queue *q) {
    if (isEmpty(q)) {
        cout << "Antrian masih kosong.\n";
        return;
    }

    address antri = q->front;
    int nomor = 1;

    while (antri != NULL) {
        cout << nomor << ". " << antri->data << endl;
        antri = antri->next;
        nomor++;
    }

    cout << "\n";
}

// -- QUEUE --

// -- MENU --

void menu() {
    cout << "=== SISTEM LAYANAN KLINIK SEHAT ===\n";
    cout << "1. Daftar Pasien Baru (Antrian)\n";
    cout << "2. Panggil Pasien Selanjutnya\n";
    cout << "3. Tampilkan Antrian Pasien Saat Ini\n";
    cout << "4. Tampilkan Riwayat Pemeriksaan\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu (1-5): ";
}

// -- MENU --

int main() {
    membuatStack(&riwayat);
    init(&antrian);

    int pilihan;

    do {
        menu();
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1: {
                string nama;
                cout << "Masukkan nama pasien : ";
                getline(cin, nama);
                if (nama.empty()) {
                    cout << "Nama tidak boleh kosong\n";
                } else {
                    enqueue(&antrian, nama);
                }
                break;
            }
            case 2: {
                if (isEmpty(&antrian)) {
                    cout << "Tidak ada pasien dalam antrian \n";
                } else {
                    string namaDipanggil = dequeue(&antrian);
                    cout << "Pasien atas nama " << namaDipanggil << " sedang diperiksa \n";
                    push(namaDipanggil, &riwayat);
                    cout << "Data pasien disimpan ke riwayat pemeriksaan.\n";
                }
                break;
            }
            case 3: {
                cetakAntrian(&antrian);
                break;
            }
            case 4: {
                cetakRiwayat(&riwayat);
                break;
            }
            case 5: {
                cout << "Keluar" << endl;
                break;
            }
            default: {
                cout << "Tidak ada dalam pilihan. Silahkan masukkan angka 1 sampai 5.\n" << endl;
            }
        }
    } while (pilihan != 5);

    return 0;
}