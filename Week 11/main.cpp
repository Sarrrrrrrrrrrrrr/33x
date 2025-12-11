#include <iostream>
#include "circularlist.h"

using namespace std;

address createData(string nama, string nim, char jenis_kelamin, float ipk) {
    infotype x;
    address P;
    
    x.nama = nama;
    x.nim = nim;
    x.jenis_kelamin = jenis_kelamin;
    x.ipk = ipk;
    
    P = alokasi(x);
    return P;
}

int main() {
    List L;
    address P1 = NULL;
    address P2 = NULL;
    
    createList(L);
    
    cout << "Coba insert first, last, dan after" << endl;
    
    P1 = createData("Danu", "04", 'L', 4.0);
    insertFirst(L, P1);

    P1 = createData("Bobi", "02", 'L', 3.71);
    insertFirst(L, P1);
    
    P1 = createData("Ali", "01", 'L', 3.3);
    insertFirst(L, P1);

    P1 = createData("Gita", "07", 'P', 3.75);
    insertLast(L, P1);
    
    address cari = findElm(L, "02");
    if (cari != NULL) {
        P2 = createData("Cindi", "03", 'P', 3.5);
        insertAfter(L, cari, P2);
    }
    cari = findElm(L, "07");
    if (cari != NULL) {
        P2 = createData("Hilmi", "08", 'L', 3.3);
        insertAfter(L, cari, P2);
    }
    
    cari = findElm(L, "04");
    if (cari != NULL) {
        P2 = createData("Eli", "05", 'P', 3.4);
        insertAfter(L, cari, P2);
    }
    
    cari = findElm(L, "05");
    if (cari != NULL) {
        P2 = createData("Fahmi", "06", 'L', 3.45);
        insertAfter(L, cari, P2);
    }

    printInfo(L);
    
    return 0;
}