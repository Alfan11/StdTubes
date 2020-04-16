#include <iostream>
#include <conio.h>
#include "list_child.h"
#include "list_parent.h"

using namespace std;

adrP P_input(){
    infotypeP x;

    cout<<"Nama Lapas        : ";
    cin>>x.namaLapas;
    cout<<"Kategori          : ";
    cin>>x.kategori;
    cout<<"Tingkat Kejahatan : ";
    cin>>x.tingkat;

    return alokasiP(x);
}

adrC C_input(){
    infotypeC x;

    cout<<"Nama Tahanan   : ";
    cin>>x.nama;
    cout<<"Gender         : ";
    cin>>x.jenisKl;
    cout<<"Umur           : ";
    cin>>x.umur;
    cout<<"No tahanan     : ";
    cin>>x.noThn;
    cout<<" "<<endl;

    return alokasiC(x);
}

void menu(ListP L){
    adrP P,Q,R;
    adrC C;
    infotypeP cari,x;
    int pil;

    do {
        system("cls");
        cout<<"1.  Insert Last Parent"<<endl;
        cout<<"2.  Show Parent X"<<endl;
        cout<<"3.  Delete Last Parent"<<endl;
        cout<<"4.  Delete Last Child From Parent"<<endl;
        cout<<"5.  Insert Child To Parent X"<<endl;
        cout<<"6.  Show Child From Parent X"<<endl;
        cout<<"7.  Show All Parent and Child"<<endl;
        cout<<"8.  Search Parent"<<endl;
        cout<<"9.  Search Child From Parent X"<<endl;
        cout<<"10. Count Parent"<<endl;
        cout<<"11. Count Child From Parent"<<endl;
        cout<<"12. Count All Parent With Child"<<endl;
        cout<<"Masukkan pilihan: ";
        cin>>pil;
        switch(pil) {
        case 1:
            P = P_input();
            insertLastP(L,P);
            break;
        case 2:
            showParent(L);
            break;
        case 3:
            deleteLastP(L,Q);
            break;
        case 4:
            deleteLastChx(L);
            break;
        case 5:
            cout<<"Nama Lapas : ";
            cin>>cari.namaLapas;
            P = searchParent(L, cari);
            if(P != NULL){
                C = C_input();
                insertLastC(child(P),C);
            } else {
                cout<<"NOT FOUND PARENT "<<endl;
            }
            system("pause");
            break;
        case 6:
            viewCh(L);
            break;
        case 7:
            viewAll(L);
            break;
        case 8:
            showSP(L);
            break;
        case 9:
            searchCh(L);
            break;
        case 10:
            coutElmP(L);
            break;
        case 11:
            viewElmCh(L);
            break;
        case 12:
            CountAll(L);
            break;
        default:
            break;
        }
    } while (pil != 0);
}

int main()
{
    /*adrP P,Q,R;
    adrC C;
    infotypeP cari,x,data;*/
    ListP LP;
    createListP(LP);



    menu(LP);


    //PARENT

//    P = P_input();
//    insertLastP(LP,P);
//    P = P_input();
//    insertLastP(LP,P);
//    P = P_input();
//    insertLastP(LP,P);
    /*
    data.namaLapas = "L1";
    data.kategori = "K1";
    data.tingkat = 1;
    P = alokasiP(data);
    insertLastP(LP,P);

    data.namaLapas = "L2";
    data.kategori = "K2";
    data.tingkat = 2;
    P = alokasiP(data);
    insertLastP(LP,P);

    data.namaLapas = "L3";
    data.kategori = "K3";
    data.tingkat = 3;
    P = alokasiP(data);
    insertLastP(LP,P);

    viewParent(LP);

    //viewParent(LP);
//
//
    cout<<"Nama Lapas : ";
    cin>>cari.namaLapas;
//
//    //CHILD
    P = searchParent(LP, cari);
    C = C_input();
    insertLastC(child(P),C);
    C = C_input();
    insertLastC(child(P),C);
//
//    //cout<<"hehe"<<endl;
//
    data.namaLapas = "L4";
    data.kategori = "K4";
    data.tingkat = 4;
    P = alokasiP(data);
    insertLastP(LP,P);
    //viewCh(LP);
//
//    //searchCh(LP);
//
    viewAll(LP);
//
//    //deleteFirstChx(LP);
//
//
//    CountAll(LP);
//
//    /*coutElmP(LP);
//    cout << " " <<endl;
//    cout << "Break" <<endl;
//
//    viewElmCh(LP);*/
////    cout<<"Nama Lapas : ";
////    cin>>cari.namaLapas;
////    P = searchParent(LP, cari);
////
////    if(P == NULL){
////        cout << "No Child and Parent"<<endl;
////    } else {
////        //ListC Q;
////        //CountElmC(Q);
////    }
    //viewAll(LP);

}

