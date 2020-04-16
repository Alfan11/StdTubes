#include "list_child.h"

void createListC(ListC &L){
    firstC(L) = NULL;
    lastC(L) = NULL;
}
adrC alokasiC(infotypeC x){
    adrC P;

    P = new elemenC;
    infoC(P) = x;
    nextC(P) = NULL;
    prevC(P) = NULL;
    return P;
}
void insertLastC(ListC &L, adrC &P){
    if (firstC(L) == NULL) {
        firstC(L) = P;
        lastC(L) = P;
    } else {
        nextC(lastC(L)) = P;
        prevC(P) = lastC(L);
        lastC(L) = P;
    }
}
adrC SearchC(ListC &L, infotypeC x){
    adrC P;

    P = firstC(L);
    while(infoC(P).noThn != x.noThn){
        P = nextC(P);
    }
    return P;
}
void printInfoC(ListC L){
    adrC P;
    P = firstC(L);
    while(P != NULL){
        cout << " >> "<<infoC(P).nama;
        P = nextC(P);
    }
}

adrC viewChild(ListC L, int Ch){
    adrC P;
    P = firstC(L);
    while((P != NULL) && (infoC(P).noThn != Ch)){
//        cout << " >> "<<infoC(P).nama;
        P = nextC(P);
    }
    if (P != NULL){
        return P;
    } else {
        return NULL;
    }
}

void deleteFirstC(ListC &L, adrC &P){
    if(firstC(L) == NULL){
        cout << "Child Not Found";
    } else if(nextC(firstC(L)) == NULL) {
        P = firstC(L);
        firstC(L) = NULL;
        lastC(L) = NULL;
        delete P;
    } else {
        P = firstC(L);
        firstC(L) = nextC(P);
        nextC(P) = NULL;
        prevC(firstC(L)) = NULL;
        delete P;
    }
}
void deleteLastC(ListC &L, adrC &P){
    if(firstC(L) == NULL){
        cout<<"Child Not Found";
    } else if(nextC(firstC(L)) == NULL) {
        P = firstC(L);
        firstC(L) = NULL;
        lastC(L) = NULL;
        delete P;
    } else {
        P = lastC(L);
        lastC(L) = prevC(P);
        nextC(lastC(L)) = NULL;
        delete P;
        /*
        P = firstC(L);
        while (nextC(P) = NULL){
            P = nextC(P);
        }
        nextC(prevC(P)) = NULL;
        lastC(L) = prevC(P);
        prevC(P) = NULL; */
    }
}

void CountElmC(ListC L){
    adrC P;
    int i;

    i = 0;
    if(firstC(L) != NULL){
        P = firstC(L);
        while(P != NULL){
            i = i + 1;
            P = nextC(P);
        }
    } else {
        cout << "Child Null"<<endl;
    }
    cout << "Jumlah Child : " << i << endl;
}

