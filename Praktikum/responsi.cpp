// ============================================================
// Sistem Antrian dan Riwayat Layanan Klinik Sehat
// Implementasi: Stack dengan Array Statis + Queue dengan Linked List
// Mengacu pada Unit 3 (Stack) dan Unit 5 (Linked List Queue)
// ============================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================
// STRUKTUR DATA STACK - ARRAY STATIS (Unit 3)
// Prinsip: LIFO - Last In First Out
// ============================================================

#define MAX_STACK 100

typedef struct {
    string item[MAX_STACK];
    int count;
} Stack;

Stack riwayat;

bool isFull(Stack *x) {
    if ((x->count) >= MAX_STACK)
        return true;
    return false;
}

bool isEmpty(Stack *x) {
    if ((x->count) == 0)
        return true;
    return false;
}

void membuatStack(Stack *x) {
    x->count = 0;
}

// Push: masukkan pasien ke riwayat
void push(string data, Stack *x) {
    if (isFull(x)) {
        cout << "Riwayat Penuh\n";
    } else {
        x->item[x->count] = data;
        ++(x->count);
    }
}

// Pop: keluarkan riwayat teratas (disertakan sebagai pelengkap)
void pop(Stack *x) {
    if (isEmpty(x)) {
        cout << "Riwayat kosong, tidak ada data yang diambil.\n";
    } else {
        --(x->count);
        cout << "Data \"" << x->item[x->count] << "\" dihapus dari riwayat.\n";
    }
}

// Cetak riwayat: LIFO, yang terakhir masuk tampil paling atas
void cetakStack(Stack *x) {
    if (isEmpty(x)) {
        cout << "[INFO] Belum ada riwayat pemeriksaan.\n";
        return;
    }
    cout << "--- Riwayat Pemeriksaan (Terbaru di Atas) ---\n";
    for (int i = x->count - 1; i >= 0; i--) {
        cout << (x->count - i) << ". " << x->item[i] << endl;
    }
    cout << "Total pasien sudah diperiksa: " << x->count << endl;
}

// ============================================================
// STRUKTUR DATA QUEUE - LINKED LIST (Unit 5)
// Prinsip: FIFO - First In First Out
// ============================================================

// Deklarasi Node untuk Linked List
typedef struct tnode *address;
struct tnode {
    string data;
    address next;
} node;

// Struktur Queue yang menampung front dan rear
typedef struct {
    address front;
    address rear;
} Queue;

Queue antrian;

void init(Queue *q) {
    q->front = NULL;
    q->rear  = NULL;
}

address alokasikan(string nilai) {
    address baru = new tnode;
    baru->data = nilai;
    baru->next = NULL;
    return baru;
}

bool isEmpty(Queue *q) {
    return (q->front == NULL);
}

// Enqueue: daftarkan pasien ke belakang antrian
void enqueue(Queue *q, string nilai) {
    address baru = alokasikan(nilai);
    if (isEmpty(q)) {
        // Antrian kosong: front dan rear tunjuk ke node yang sama
        q->front = baru;
        q->rear  = baru;
    } else {
        // Sambungkan node baru ke belakang, geser rear
        q->rear->next = baru;
        q->rear = baru;
    }
    cout << "Pasien atas nama \"" << nilai << "\" berhasil didaftarkan ke antrian.\n";
}

// Dequeue: keluarkan dan hapus pasien dari depan antrian
string dequeue(Queue *q) {
    if (isEmpty(q)) {
        return "";
    }
    address hapus = q->front;
    string nilai  = hapus->data;
    q->front = q->front->next;
    // Jika antrian jadi kosong, rear juga harus NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }
    delete hapus;
    return nilai;
}

// Cetak seluruh antrian dari depan ke belakang
void cetakQueue(Queue *q) {
    if (isEmpty(q)) {
        cout << "[INFO] Antrian pasien saat ini kosong.\n";
        return;
    }
    cout << "--- Daftar Antrian Pasien (depan -> belakang) ---\n";
    address jalan = q->front;
    int nomor = 1;
    while (jalan != NULL) {
        cout << nomor << ". " << jalan->data << endl;
        jalan = jalan->next;
        nomor++;
    }
}

// ============================================================
// MENU INTERAKTIF
// ============================================================

void tampilkanMenu() {
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

// ============================================================
// MAIN
// ============================================================

int main() {
    membuatStack(&riwayat);
    init(&antrian);

    int pilihan;

    do {
        tampilkanMenu();
        cin >> pilihan;
        cin.ignore();

        cout << endl;

        switch (pilihan) {
            case 1: {
                string nama;
                cout << "Masukkan nama pasien: ";
                getline(cin, nama);
                if (nama.empty()) {
                    cout << "[ERROR] Nama tidak boleh kosong!\n";
                } else {
                    enqueue(&antrian, nama);
                }
                break;
            }
            case 2: {
                if (isEmpty(&antrian)) {
                    cout << "[INFO] Tidak ada pasien dalam antrian.\n";
                } else {
                    string namaDipanggil = dequeue(&antrian);
                    cout << "Pasien atas nama \"" << namaDipanggil << "\" sedang diperiksa.\n";
                    // Otomatis simpan ke Stack riwayat
                    push(namaDipanggil, &riwayat);
                    cout << "Data pasien disimpan ke riwayat pemeriksaan.\n";
                }
                break;
            }
            case 3: {
                cetakQueue(&antrian);
                break;
            }
            case 4: {
                cetakStack(&riwayat);
                break;
            }
            case 5: {
                cout << "Terima kasih. Program selesai.\n";
                break;
            }
            default: {
                cout << "[ERROR] Pilihan tidak valid. Masukkan angka 1 sampai 5.\n";
                break;
            }
        }

    } while (pilihan != 5);

    return 0;
}