#include "list_parent.h"

void createListP(ListP &L){
    firstP(L) = NULL;
}
adrP alokasiP(infotypeP x){
    adrP P;

    P = new elemenP;
    infoP(P) = x;
    nextP(P) = NULL;
    createListC(child(P));
    return P;
}
void insertLastP(ListP &L, adrP P){
    adrP Q;
    if(firstP(L) == NULL){
        firstP(L) = P;
    } else {
    Q = firstP(L);
    while(nextP(Q) != NULL){
        Q = nextP(Q);
        }
    nextP(Q) = P;
    }
}
adrP searchParent(ListP L, infotypeP x){
    adrP P = NULL;
    if(firstP(L) == NULL){
        cout<<"EMPTY";
    } else {
        P = firstP(L);
        while((P != NULL) && (infoP(P).namaLapas != x.namaLapas)){
            P = nextP(P);
        }
    }
    return P;
}
void showSP(ListP L){
    adrP W;
    infotypeP x;

    cout<<"Nama Lapas : ";
    cin>>x.namaLapas;
    W = searchParent(L,x);
    if(W != NULL){
        cout << "FOUND" <<endl;
        cout << infoP(W).namaLapas<<endl;
        cout << infoP(W).kategori<<endl;
    } else {
        cout<<"NOT FOUND";
    }
    system("pause");
}
void showParent(ListP L){
    adrP P;

    if (firstP(L) == NULL) {
        cout<<"List kosong!"<<endl;
    } else {
        P = firstP(L);
        while (P != NULL) {
            cout<<"Nama Lapas : "<<infoP(P).namaLapas<<endl;
            cout<<"Kategori   : "<<infoP(P).kategori<<endl;
            P = nextP(P);
        };
    }
    system("pause");
}

void viewAll(ListP L){
    adrP P;
    if(firstP(L) == NULL){
        cout<<"K O S O N K";
    } else {
        P = firstP(L);
        ListC C;
        while (P != NULL) {
            C = child(P);
            if (firstC(C) == NULL) {
                cout<<infoP(P).namaLapas<<endl;
                cout<<"List Kosong"<<endl;
            } else {
                cout<<infoP(P).namaLapas<<endl;
                printInfoC(child(P));
                cout<<" "<<endl;
            }
            P = nextP(P);
        }
//        P = firstP(L);
//        while(P != NULL){
//            cout <<" "<<endl;
//            cout<<infoP(P).namaLapas<<endl;
//            printInfoC(child(P));
//            cout<<" "<<endl;
//            P = nextP(P);
        //}
    }
    system("pause");
}

void viewCh(ListP L){
    adrP P;
    infotypeP x;

    cout<<"Cari parent : ";
    cin>>x.namaLapas;

    P = searchParent(L,x);
    if(P != NULL){
        cout<<" "<<endl;
        printInfoC(child(P));
        cout<<" "<<endl;
    } else {
        cout<<"Parent not Found";
    }
    system("pause");
}

void searchCh(ListP L){
    adrP P;
    infotypeP x;
    infotypeC searchChild;

    cout<<"Cari parent : ";
    cin>>x.namaLapas;

    P = searchParent(L,x);
    if(P != NULL){
        cout << " "<<endl;
        cout << "No tahanan : ";
        cin >> searchChild.noThn;
        adrC C = viewChild(child(P), searchChild.noThn);
        if(C != NULL ){
            cout<<"Nama Tahanan : " << infoC(C).nama<<endl;
            cout<<"No Tahanan   : " << infoC(C).noThn;
            cout<<" "<<endl;
        } else {
            cout << "child not found";
        }
    } else {
            cout << "NOT FOUND";
        }
    system("pause");
}

void deleteFirstP(ListP &L, adrP &P) {
    if(firstP(L) == NULL){
        cout << "Data Kosong";
    } else if(nextP(firstP(L)) == NULL) {
        P = firstP(L);
        firstP(L) = NULL;
        //delete P;
    } else {
        P = firstP(L);
        firstP(L) = nextP(P);
        nextP(P) = NULL;
        //delete P;
    }
    system("pause");
}

void deleteLastP(ListP L, adrP &P){
    adrP Q;
    if (firstP(L) == NULL){
        cout << "Data masih kosong" << endl;
    }
    else if (nextP(firstP(L)) == NULL){
        P = firstP(L);
        firstP(L) = NULL;
    }
    else{
        Q = firstP(L);
        while (nextP(nextP(Q)) != NULL){
            Q = nextP(Q);
        }
        P = nextP(Q);
        nextP(Q) = NULL;
    }
    system("pause");
}

void deleteFirstChx(ListP L){
    adrP P;
    infotypeP x;

    cout<<"Cari parent : ";
    cin>>x.namaLapas;

    P = searchParent(L,x);
    if(P != NULL){
        adrC C = firstC(child(P));
        deleteFirstC(child(P),C);
    } else {
        cout << "Data Kosong";
    }
    system("pause");
}

void deleteLastChx(ListP L){
    adrP P;
    infotypeP x;

    cout<<"Cari parent : ";
    cin>>x.namaLapas;

    P = searchParent(L,x);
    if(P != NULL){
        adrC C;
        deleteLastC(child(P),C);
    } else {
        cout << "Data Kosong";
    }
    system("pause");
}

void coutElmP(ListP L){
    adrP P;
    int i;

    i = 0;
    if(firstP(L) == NULL){
        cout<<"Parent Kosong"<<endl;
    } else {
            P = firstP(L);
            while(P != NULL){
                i = i + 1;
                P = nextP(P);
            }
        }
    cout << "Jumlah parent : " << i <<endl;
    system("pause");
}

void viewElmCh(ListP L){
    adrP P;
    infotypeP x;

    cout<<"Cari parent : ";
    cin>>x.namaLapas;

    P = searchParent(L,x);
    if(firstP(L) == NULL){
        cout<<"Data Anak Tidak ada"<<endl;
    } else {
        //cout<<" "<<endl;
        CountElmC(child(P));
    }
    system("pause");
}

void CountAll(ListP L){
    adrP P,Q;

    if(firstP(L) == NULL){
        cout<<"No Parent And Child"<<endl;
    } else {
        P = firstP(L);
            if(P != NULL){
                //cout<<"Jumlah Parent : ";
                coutElmP(L);
                while(P != NULL){
                    cout<<infoP(P).namaLapas<<endl;
                    //cout<<"Jumlah Child : ";
                    CountElmC(child(P));
                    cout<<" "<<endl;
                    P = nextP(P);
                }
            } else {
                cout << "Parent Null"<<endl;
            }
    }
    system("pause");
}


//void deleteAfterP(ListP L, adrP PrecP, adrP &P){
//    if(firstP(L) == NULL){
//        cout << "EMPTY";
//    } else {
//        adrP Q = firstP(L);
//        while (Q != PrecP){
//            Q = nextP(Q);
//        }
//        if (Q == PrecP){
//            P = nextP(Q);
//            nextP(Q) = nextP(P);
//            nextP(P) = NULL;
//        } else {
//            cout << "Not Found";
//        }
//    }
//}


