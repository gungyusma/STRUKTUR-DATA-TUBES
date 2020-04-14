#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include<iostream>
using namespace std;

#include "buku.h"
#define Nil NULL
#define last(L) L.last
#define infoP(P) P->info //ini tadi bermasalah
#define nextP(P) P->nextP
#define prevP(P) P->prevP



struct penulis {
    string penulis;
    int yangditulis;
};

typedef struct penulis info;
typedef struct elmpenulis *address;

struct elmpenulis {
    address nextP, prevP;
    addressB nextB;
    info info;
};

struct list {
    address first, last;
};

void createlist(list &L);
address allocate(string nama, int yangditulis);
void insertlastpenulis(list &L, address P);
void insertfirstpenulis(list &L, address P);
void deletefirstpenulis(list &L, address &P);
void deleteafterpenulis(list &L, address &P, address Q);
void deletelastpenulis(list &L, address &P);
address searchpen(list L, string nama);
void showpenulis(list L, address P);
void showall(list L);
void connect(list L, string penulis, list_buku Lb);
void deletefirstbuku(address A, list_buku &L, addressB &P);






#endif // HEADER_H_INCLUDED
