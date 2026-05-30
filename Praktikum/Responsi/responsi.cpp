#include <iostream>
#include <string>
using namespace std;

typedef struct node *address;
struct node{
    int data;
    address next;
};

typedef struct {
    address front;
    address rear;
} Queue;

Queue antrian;

address alokasi(int nilai) {
    address baru = new node;
    baru->data = nilai;
    baru->next = NULL;
    return baru;
}

int main() {

}