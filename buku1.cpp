#include<iostream>
#include "buku.h"
using namespace std;

void createlistbuku(list_buku &L) {
    first(L) = NULL;
}
void insertlastbuku(list_buku &L, addressB P) {
    if (first(L) == NULL) {
        first(L) = P;
    } else {
        addressB Q;
        Q = first(L);
        while (nextB(Q) != NULL) {
            Q = nextB(Q);
        }
        nextB(Q) = P;
    }
}

void deleteafterbuku(list_buku &L, addressB &P, addressB Q) {
    nextB(Q) = nextB(P);
    nextB(P) = NULL;
}

void deletelastbuku(list_buku &L, addressB &P) {
    addressB Q;
    Q = first(L);
    while (nextB(Q) != P) {
        Q = nextB(Q);
    }
    nextB(Q) = NULL;
}

void deletebuku(list_buku &L, addressB &P, string judul) {
    if (first(L) == NULL) {
        cout<<"kosong"<<endl;
    } else {

        if (nextB(P) == NULL) {
            deletelastbuku(L, P);
        } else {
            addressB Q = first(L);
            while (nextB(Q) != P) {
                Q = nextB(Q);
            }

            deleteafterbuku(L, P, Q);
        }
    }
}

addressB allocate_buku(string judul) {
    addressB P;
    P = new nodeB;
    info(P).judul = judul;
    info(P).yangnulis = 1;
    nextB(P) = NULL;
    return P;
}

addressB findelm(list_buku L, string x) {
    addressB P;
    P = first(L);
    while ((info(P).judul != x) && (P != NULL)) {
        P = nextB(P);
    }

    if (info(P).judul == x) {
        return P;
    } else {
        return NULL;
    }
}

void printinfobuku(list_buku L) {
    addressB P = first(L);
    while (P != NULL) {

        cout<<"Judul Buku : "<<info(P).judul<<endl;
        cout<<"Ditulis oleh "<<info(P).yangnulis<<" penulis."<<endl;
        cout<<endl;
        P = nextB(P);
    }
}

int jumbuku(list_buku L) {
    int jum;
    addressB P = first(L);
    jum=1;
    while (P!= NULL) {
        jum++;
        P = nextB(P);
    }
}
