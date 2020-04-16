#ifndef LIST_PARENT_H_INCLUDED
#define LIST_PARENT_H_INCLUDED
#include <stdlib.h>

#include <iostream>
#include "list_child.h"
using namespace std;

#define nil NULL
#define nextP(P) (P)->nextP
#define firstP(L) (L).firstP
#define infoP(P) (P)->infoP
#define child(P) P->child

typedef struct infotypeP;

struct infotypeP{
    string namaLapas;
    string kategori;
    int tingkat;
};
typedef struct elemenP* adrP;

struct elemenP{
    infotypeP infoP;
    adrP nextP;
    ListC child;
};

struct ListP{
    adrP firstP;
};

void createListP(ListP &L);
adrP alokasiP(infotypeP x);
void insertLastP(ListP &L, adrP P);
void deleteFirstP(ListP &L, adrP &P);
void deleteLastP(ListP L, adrP &P);
void showParent(ListP L);
void showSP(ListP L);
void countElmCh(ListP L);
void coutElmP(ListP L);
void deleteFirstChx(ListP L);
void deleteLastChx(ListP L);
adrP searchParent(ListP L, infotypeP x);
void viewAll(ListP L);
void viewCh(ListP L);
void viewElmCh(ListP L);
void searchCh(ListP L);
void CountAll(ListP L);
#endif // LIST_PARENT_H_INCLUDED
