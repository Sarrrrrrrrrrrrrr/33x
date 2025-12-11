#include "multilist.h"
#include <iostream>
using namespace std;

address_anak alokasiAnak(infotype x) {
    address_anak P = new elemen_anak;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

void insertLastAnak(list_anak &LA, address_anak PA) {
    if (LA.first == Nil) {
        LA.first = PA;
        LA.last = PA;
    } else {
        LA.last->next = PA;
        PA->prev = LA.last;
        LA.last = PA;
    }
}

void printInfo(list_induk L) {
    address_induk PI = L.first;
    while (PI != Nil) {
        cout << "Induk: " << PI->info << endl;
        address_anak PA = PI->anak.first;
        while (PA != Nil) {
            cout << "  Anak: " << PA->info << endl;
            PA = PA->next;
        }
        PI = PI->next;
    }
}


void insertFirstAnak(list_anak &L, address_anak P){
    if (L.first == Nil){
        L.first = P;
        L.last = P;
    } else {
        P -> next = L.first;
        L.first->prev = P;
        L.first = P;
    }
}

void insertAfterAnak(list_anak &L, address_anak P, address_anak Prec) {
    if (Prec != Nil) {
        P-> next = Prec ->next;
        P->prev = Prec;
        if (Prec->next != Nil) {
            Prec -> next -> prev = P;
        } else {
            L.last = P;
        }
        Prec -> next = P;
    }
}

void delFirstAnak(list_anak &L, address_anak &P) {
    P = L.first;
    if (L.first != Nil) {
        if(L.first == L.last){
            L.first = Nil;
            L.last = Nil;
        } else {
            L.first = P -> next;
            L.first -> prev = Nil;
            P -> next = Nil;
        }
    }
}
void delLastAnak(list_anak &L, address_anak &P) {
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

void delAfterAnak(list_anak &L, address_anak &P, address_anak Prec){
    P = Prec -> next;
    if (P != Nil) {
        Prec -> next = P -> next;
        if (P -> next != Nil){
            P->next->prev = Prec;
        } else {
            L.last = Prec;
        }
        P -> next = Nil;
        P -> prev = Nil;
    }

}
void dealokasiAnak(address_anak P){
    delete P;
}

void delPAnak(list_anak &L, infotypeanak X) {
    address_anak P = findElmAnak(L, X);
    
    if (P != Nil) {
        address_anak P_Hapus;
        
        if (P == L.first) {
            delFirstAnak(L, P_Hapus);
        } else if (P == L.last) {
            delLastAnak(L, P_Hapus);
        } else {
            address_anak Prec = P->prev;
            delAfterAnak(L, P_Hapus, Prec);
        }
        dealokasiAnak(P);
    }
}
address_anak findElmAnak(list_anak L, infotypeanak x) {
    address_anak P = L.first;
    while (P != Nil) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}