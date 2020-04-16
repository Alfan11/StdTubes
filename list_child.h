#ifndef LIST_CHILD_H_INCLUDED
#define LIST_CHILD_H_INCLUDED
#include <stdlib.h>
#include <iostream>
using namespace std;

#define nextC(P) P->nextC
#define prevC(P) P->prevC
#define firstC(L) L.firstC
#define lastC(L) L.lastC
#define infoC(P) P->infoC

struct infotypeC{
    string nama;
    char jenisKl;
    int umur;
    int noThn;
};
typedef struct elemenC *adrC;

struct elemenC{
    infotypeC infoC;
    adrC nextC, prevC;
};

struct ListC {
    adrC firstC;
    adrC lastC;
};

bool isEmpty(ListC L);
void createListC(ListC &L);
adrC alokasiC(infotypeC x);
void insertLastC(ListC &L, adrC &P);
void deleteFirstC(ListC &L, adrC &P);
void deleteLastC(ListC &L, adrC &P);
adrC SearchC(ListC &L, infotypeC x);
void printInfoC(ListC L);
adrC viewChild(ListC L, int Ch);
void CountElmC(ListC L);

#endif // LIST_CHILD_H_INCLUDED
