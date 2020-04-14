#include<iostream>
#include "header.h"

using namespace std;

void createlist(list &L) {
    first(L) = 0;
    last(L) = 0;
}

address allocate(string nama, int yangditulis) {
    address P = new elmpenulis;
    infoP(P).penulis = nama;
    infoP(P).yangditulis = yangditulis;
    nextP(P) = 0;
    prevP(P) = 0;
    nextB(P) = 0;

    return P;
}

void insertlastpenulis(list &L, address P) {
    if (first(L) == 0) {
        first(L) = P;
        last(L) = P;
    } else {
        nextP(last(L)) = P;
        prevP(P) = last(L);
        last(L) = P;
    }
}

void insertfirstpenulis(list &L, address P) {
    if (first(L) == 0) {
        first(L) = P;
        last(L) = P;
    } else {
        nextP(P) = first(L);
        prevP(first(L)) = P;
        first(L) = P;
    }
}

void deletefirstpenulis(list &L, address &P){
    if (first(L) == 0) {
        cout<<"kosong"<<endl;
    } else if (nextP(first(L)) == 0) {
        P = first(L);
        first(L) = 0;
        last(L) = 0;
    } else {
        P = first(L);
        first(L) = nextP(P);
        prevP(first(L)) = 0;
        nextP(P) = 0;
    }
}

void deleteafterpenulis(list &L, address &P, address Q) {
    P = nextP(Q);
    nextP(Q) = nextP(P);
    prevP(nextP(P)) = Q;
    prevP(P) = 0;
    nextP(P) = 0;

}

void deletelastpenulis(list &L, address &P) {
    if (first(L) == 0) {
        cout<<"kosong"<<endl;
    } else if (nextP(first(L)) == 0) {
        P = first(L);
        first(L) = 0;
        last(L) = 0;
    } else {
        P = last(L);
        last(L) = prevP(P);
        prevP(P) = 0;
        nextP(last(L)) = 0;
    }
}

address searchpen(list L, string nama) {
    address P = first(L);
    while (P != 0) {
        if (infoP(P).penulis == nama) {
            return P;
        }
        P = nextP(P);
    }
    return 0;

}

void showpenulis(list L, address P) {
    addressB A;

    A = nextB(P);
    cout<<"Berikut adalah daftar buku dari "<<infoP(P).penulis<<endl;
    while (A != 0) {
        cout<<"- "<<info(A).judul<<endl;
        A = nextB(A);
    }
    cout<<endl;
}

void showall(list L) {
    address P = first(L);
    addressB A;
    if (P == NULL) {
        cout<<"Maaf, belum ada data yang tersimpan."<<endl;
    }
    while (P != 0) {

        cout<<"Penulis : "<<infoP(P).penulis<<endl<<"Telah menulis sebanyak "<<infoP(P).yangditulis<<" buku."<<endl;
        cout<< "Berikut adalah daftar buku yang ditulis."<<endl<<endl;
        A = nextB(P);
        while (A != 0) {

            cout<<"- "<<info(A).judul<<endl;
            A = nextB(A);
        }
       cout<<"====================================================="<<endl<<endl;
        P = nextP(P);
    }
    cout<<endl;

}

void deletefirstbuku(address A, list_buku &L, addressB &P) {
    addressB R = nextB(P);
    nextB(P) = NULL;
    nextB(A) = R;
}

void connect(list L, string penulis, list_buku Lb) {
    address P = searchpen(L, penulis);
    nextB(P) = first(Lb);
}
