#ifndef MULTILIST_H_INCLUDED
#define MULTILIST_H_INCLUDED
#define Nil NULL

typedef int infotype;
typedef struct elemen_induk *address_induk;
typedef struct elemen_anak *address_anak;
typedef int infotypeinduk;
typedef int infotypeanak;

struct elemen_anak {
    infotype info;
    address_anak next, prev;
};

struct list_anak {
    address_anak first, last;
};

struct elemen_induk {
    infotype info;
    list_anak anak;
    address_induk next, prev;
};

struct list_induk {
    address_induk first, last;
};


void createList(list_induk &L);
bool listEmpty(list_induk L);
address_induk alokasi(infotypeinduk x);
void dealokasi(address_induk P);

void createListAnak(list_anak &L);
bool listEmptyAnak(list_anak L);
address_anak alokasiAnak(infotypeanak x);
void dealokasiAnak(address_anak P);

void insertFirst(list_induk &L, address_induk P);
void insertLast(list_induk &L, address_induk P);
void insertAfter(list_induk &L, address_induk P, address_induk Prec);

void insertFirstAnak(list_anak &L, address_anak P);
void insertLastAnak(list_anak &L, address_anak P);
void insertAfterAnak(list_anak &L, address_anak P, address_anak Prec);

void delFirst(list_induk &L, address_induk &P);
void delLast(list_induk &L, address_induk &P);
void delAfter(list_induk &L, address_induk &P, address_induk Prec);
void delP(list_induk &L, infotypeinduk X);

void delFirstAnak(list_anak &L, address_anak &P);
void delLastAnak(list_anak &L, address_anak &P);
void delAfterAnak(list_anak &L, address_anak &P, address_anak Prec);
void delPAnak(list_anak &L, infotypeanak X);

address_induk findElm(list_induk L, infotypeinduk x);
address_anak findElmAnak(list_anak L, infotypeanak x);

void printInfo(list_induk L);
void printInfoAnak(list_anak L);
int nbList(list_induk L);

#endif
