#include "circularlist.h"

void createList(List &L) {
    L.first = NULL;
}

address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void dealokasi(address P) {
    delete P;
}

void insertFirst(List &L, address P) {
    if (L.first == NULL) {
        L.first = P;
        P->next = P;
        P->prev = P;
    } else {
        address last = L.first->prev; 
        
        P->next = L.first;
        P->prev = last;
        
        L.first->prev = P;
        last->next = P;
        
        L.first = P; 
    }
}

void insertLast(List &L, address P) {
    if (L.first == NULL) {
        insertFirst(L, P);
    } else {
        address last = L.first->prev;
        
        P->next = L.first;
        P->prev = last;
        
        last->next = P;
        L.first->prev = P;
    }
}

void insertAfter(List &L, address Prec, address P) {
    
    P->next = Prec->next;
    P->prev = Prec;
    
    Prec->next->prev = P;
    Prec->next = P;
}

void deleteFirst(List &L, address &P) {
    P = L.first;
    if (L.first == NULL) {
        return; 
    } 
    
    if (P->next == P) { 
        
        L.first = NULL;
    } else {
        address last = P->prev;
        L.first = P->next;
        
        L.first->prev = last;
        last->next = L.first;
    }
    P->next = NULL;
    P->prev = NULL;
}

void deleteLast(List &L, address &P) {
    if (L.first == NULL) {
        P = NULL;
        return;
    }
    
    address last = L.first->prev;
    
    if (last == L.first) {
        deleteFirst(L, P);
    } else {
        P = last;
        address prevLast = last->prev;
        
        prevLast->next = L.first;
        L.first->prev = prevLast;
        
        P->next = NULL;
        P->prev = NULL;
    }
}

void deleteAfter(List &L, address Prec, address &P) {
    P = Prec->next;
    if (P == Prec) {
        deleteFirst(L, P);
    } else {
        Prec->next = P->next;
        P->next->prev = Prec;
        
        P->next = NULL;
        P->prev = NULL;
    }
}

address findElm(List L, string nim) {
    if (L.first == NULL) return NULL;
    
    address P = L.first;
    do {
        if (P->info.nim == nim) {
            return P;
        }
        P = P->next;
    } while (P != L.first); 
    
    return NULL;
}

void printInfo(List L) {
    if (L.first == NULL) {
        cout << "List Kosong." << endl;
        return;
    }
    
    address P = L.first;
    cout << "--- Data Mahasiswa (Circular) ---" << endl;
    do {
        cout << "NIM: " << P->info.nim << " | Nama: " << P->info.nama 
             << " | IPK: " << P->info.ipk << endl;
        P = P->next;
    } while (P != L.first); // Loop sampai kembali ke First
    cout << "---------------------------------" << endl;
}