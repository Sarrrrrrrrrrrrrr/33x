#include <iostream>
#define Nil NULL
using namespace std;

typedef int infotype; // mendefinisikan data infotype sebagai int
typedef struct elmlist *address; // mendefinisikan tipe address sebagai pointer ke struct elmlist

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

void insertFirst(List &L, address P) {
    P -> next = L.first;
    P -> prev = Nil;
    if (L.first != Nil) L.first -> prev = P;
    else L.last = P;
    L.first = P;
}

void insertLast(List &L, address P) {
    P->prev = L.last;
    P->next = Nil;
    if (L.last != Nil) L.last -> next = P;
    else L.first = P;
    L.last = P;
}

void insertAfter(List &L, address P, address R){
    P -> next = R -> next;
    P -> prev = R;
    if (R -> next != Nil) R -> next -> prev = P;
    else L.last = P;
    R -> next = P;
}

address alokasi(infotype x){ // Definisi fungsi alokasi untuk membuat elemen baru
    address P = new elmlist; // Alokasikan memori baru untuk elemen
    P -> info = x;
    P -> next = Nil;
    P -> prev = Nil;
    return P;
}
//Modifikasi Codingan untuk Unguided 5.1
void insertBefore(List &L, address P, address R) {
P->next = R;
P->prev = R->prev;
if (R->prev != Nil) R->prev->next = P;
else L.first = P;
R->prev = P;
}

void printInfo(List L){
    address P = L.first;
    while (P != Nil) {
        cout << P -> info << " ";
        P = P -> next;
    }
    cout << endl;
}
//Penambahan codingan untuk guided 5.1
void printReverse(List L) {
address P = L.last;
cout << "List (belakang -> depan): ";
while (P != Nil) {
cout << P->info << " ";
P = P->prev;
}
cout << endl;
}


int main() {
List L;
L.first = Nil;
L.last = Nil;

//Output  5.1
address P1 = alokasi(10);
address P2 = alokasi(20);
address P3 = alokasi(30);
address P4 = alokasi(25);


insertFirst(L, P1);
insertLast(L, P2);
insertLast(L, P3);


cout << "Sebelum insertBefore:" << endl;
printInfo(L);


insertBefore(L, P4, P3);
cout << "Setelah insertBefore (25 sebelum 30):" << endl;
printInfo(L);


cout << "Cetak terbalik:" << endl;
printReverse(L);
}