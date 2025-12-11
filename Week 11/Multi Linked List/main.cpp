#include <iostream>
#include "multilist.h"

using namespace std;

int main() {
    list_induk L;
    createList(L);


    address_induk P1 = alokasi(1);
    insertLast(L, P1); 


    insertLastAnak(P1->anak, alokasiAnak(10));
    insertLastAnak(P1->anak, alokasiAnak(11));

  
    address_induk P2 = alokasi(2);
    insertLast(L, P2);
    
    insertLastAnak(P2->anak, alokasiAnak(20));
    insertLastAnak(P2->anak, alokasiAnak(21));
    insertLastAnak(P2->anak, alokasiAnak(22));

    address_induk P3 = alokasi(3);
    insertLast(L, P3);
    
    insertLastAnak(P3->anak, alokasiAnak(30));

 
    cout << "=== ISI LIST AWAL ===" << endl;
    printInfo(L);

   
    cout << endl << "=== MENGHAPUS INDUK 2 (DAN ANAKNYA) ===" << endl;
    delP(L, 2);
    printInfo(L);

    
    cout << endl << "=== MENGHAPUS ANAK 11 DARI INDUK 1 ===" << endl;

    address_induk CariInduk = findElm(L, 1);
    if (CariInduk != Nil) {

        delPAnak(CariInduk->anak, 11);
    }
    printInfo(L);

    return 0;
}