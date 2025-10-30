#include <iostream>
#define Nil NULL
using namespace std;


typedef int infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
    address prev;
};

struct List {
    address first;
    address last;
};

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = Nil;
}

void createList(List &L) {
    L.first = Nil;
    L.last = Nil;
}

void insertFirst(List &L, address P) {
    P->next = L.first;
    P->prev = Nil;
    if (L.first != Nil)
        L.first->prev = P;
    else
        L.last = P;
    L.first = P;
}

void printInfo(List L) {
    address P = L.first;
    cout << "List: ";
    while (P != Nil) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

// Unguided 5.2 — deleteByValue() dan deleteAll()
//void deleteByValue(List &L, infotype x) {
  //  address P = L.first;
    //while (P != Nil && P->info != x) {
      //  P = P->next;
    //}

    //if (P == Nil) {
      //  cout << "Data " << x << " tidak ditemukan." << endl;
        //return;
    //}

    //if (P == L.first) {
      //  L.first = P->next;
        //if (L.first != Nil)
          //  L.first->prev = Nil;
        //else
          //  L.last = Nil;
    //} else if (P == L.last) {
      //  L.last = P->prev;
       // L.last->next = Nil;
    //} else {
      //  P->prev->next = P->next;
        //P->next->prev = P->prev;
   // }

    //cout << "Menghapus data: " << x << endl;
    //dealokasi(P);
//}

//void deleteAll(List &L) {
  //  address P = L.first;
    //int count = 0;

    //while (P != Nil) {
      //  address temp = P;
        //P = P->next;
        //dealokasi(temp);
        //count++;
    //}

    //L.first = Nil;
    //L.last = Nil;
    //cout << "Semua elemen dihapus (" << count << " data)." << endl;

// ==================================================
// Bagian Modifikasi untuk Unguided 5.3
// ==================================================
//
// void smartInsert(List &L, infotype x) {
//     address P = alokasi(x);
//     cout << ">> Menyisipkan " << x << "..." << endl;
//
//     if (L.first == Nil) {
//         cout << "List kosong, memasukkan " << x << " sebagai elemen pertama." << endl;
//         insertFirst(L, P);
//     } 
//     else if (x < L.first->info) {
//         cout << x << " lebih kecil dari elemen pertama, disisipkan di depan." << endl;
//         insertFirst(L, P);
//     } 
//     else if (x > L.last->info) {
//         cout << x << " lebih besar dari elemen terakhir, disisipkan di akhir." << endl;
//         insertLast(L, P);
//     } 
//     else {
//         address Q = L.first;
//         while (Q != Nil && Q->info < x) Q = Q->next;
//
//         if (Q != Nil && Q->info == x) {
//             cout << "Nilai " << x << " sudah ada, tidak disisipkan (hindari duplikat)." << endl;
//             dealokasi(P);
//             return;
//         }
//
//         P->next = Q;
//         P->prev = Q->prev;
//         Q->prev->next = P;
//         Q->prev = P;
//
//         cout << x << " disisipkan sebelum elemen " << Q->info << endl;
//     }
// }
//
// void conditionalDelete(List &L, infotype batas) {
//     cout << ">> Menghapus semua elemen dengan nilai lebih besar dari " << batas << endl;
//     address P = L.first;
//     int count = 0;
//
//     while (P != Nil) {
//         address temp = P;
//         P = P->next;
//         if (temp->info > batas) {
//             cout << "Menghapus " << temp->info << endl;
//
//             if (temp == L.first) {
//                 L.first = temp->next;
//                 if (L.first != Nil) L.first->prev = Nil;
//                 else L.last = Nil;
//             } else if (temp == L.last) {
//                 L.last = temp->prev;
//                 if (L.last != Nil) L.last->next = Nil;
//             } else {
//                 temp->prev->next = temp->next;
//                 temp->next->prev = temp->prev;
//             }
//
//             dealokasi(temp);
//             count++;
//         }
//     }
//
//     cout << "Total elemen yang dihapus: " << count << endl;
// }
//
// int main() {
//     List L;
//     createList(L);
//
//     cout << "=== TASK 3: SMART INSERT & CONDITIONAL DELETE ===" << endl;
//
//     smartInsert(L, 50);
//     smartInsert(L, 20);
//     smartInsert(L, 70);
//     smartInsert(L, 40);
//     smartInsert(L, 60);
//     smartInsert(L, 70); 
//
//     cout << endl << "List setelah smartInsert:" << endl;
//     printInfo(L);
//
//     cout << endl;
//     conditionalDelete(L, 50);
//     cout << "List setelah conditionalDelete:" << endl;
//     printInfo(L);
// }

int main() {
    List L;
    createList(L);

    insertFirst(L, alokasi(10));
    insertFirst(L, alokasi(20));
    insertFirst(L, alokasi(30));

    cout << "List awal: ";
    printInfo(L);

}
