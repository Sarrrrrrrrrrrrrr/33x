#include "multilist.h"
#include <iostream>
using namespace std;

void createList(list_induk &L) {
    L.first = Nil;
    L.last = Nil;
}

bool listEmpty(list_induk L) {
    return (L.first == Nil);
}

void createListAnak(list_anak &L) {
    L.first = Nil;
    L.last = Nil;
}

bool listEmptyAnak(list_anak L) {
    return (L.first == Nil);
}

address_induk alokasi(infotype x) {
    address_induk P = new elemen_induk;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    P->anak.first = Nil;
    P->anak.last = Nil;
    return P;
}

void dealokasi(address_induk P) {
    delete P;
}

void insertFirst(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        P->next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertLast(list_induk &L, address_induk P) {
    if (L.first == Nil) {
        L.first = P;
        L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertAfter(list_induk &L, address_induk P, address_induk Prec) {
    if (Prec != Nil) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != Nil) {
            Prec->next->prev = P;
        } else {
            L.last = P;
        }
        Prec->next = P;
    }
}

address_induk findElm(list_induk L, infotype x) {
    address_induk P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

void delFirst(list_induk &L, address_induk &P) {
    P = L.first;
    if (L.first != Nil) {
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P->next;
            L.first->prev = Nil;
            P->next = Nil;
        }
    }
}

void delLast(list_induk &L, address_induk &P) {
    P = L.last;
    if (L.last != Nil) {
        if (L.first == L.last) {
            L.first = Nil;
            L.last = Nil;
        } else {
            L.last = P->prev;
            L.last->next = Nil;
            P->prev = Nil;
        }
    }
}

void delAfter(list_induk &L, address_induk &P, address_induk Prec) {
    P = Prec->next;
    if (P != Nil) {
        Prec->next = P->next;
        if (P->next != Nil) {
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P->next = Nil;
        P->prev = Nil;
    }
}

void delP(list_induk &L, infotypeinduk X) {
    address_induk P = findElm(L, X);
    
    if (P != Nil) {
        
        address_anak anakSekarang = P->anak.first;
        address_anak anakHapus;
        while (anakSekarang != Nil) {
            anakHapus = anakSekarang;
            anakSekarang = anakSekarang->next;
            dealokasiAnak(anakHapus);
        }
        P->anak.first = Nil;
        P->anak.last = Nil;

     
        address_induk P_Hapus;
        
        if (P == L.first) {
            delFirst(L, P_Hapus);
        } else if (P == L.last) {
            delLast(L, P_Hapus);
        } else {
            address_induk Prec = P->prev;
            delAfter(L, P_Hapus, Prec);
        }
        
        dealokasi(P);
    }
}

void printInfoAnak(list_anak L) {
    address_anak PA = L.first;
    while (PA != Nil) {
        cout << PA->info << " ";
        PA = PA->next;
    }
}

int nbList(list_induk L) {
    int count = 0;
    address_induk P = L.first;
    while (P != Nil) {
        count++;
        P = P->next;
    }
    return count;
}