#include<iostream>
#include<string>

using namespace std;
#define Nil NULL
#define info(P) P->info
#define nextB(P) P->nextB
#define first(L) L.first


struct child {
    string judul;
    int yangnulis;
};

typedef struct child infotypeB;
typedef struct nodeB *addressB;

struct nodeB {
    infotypeB info;
    addressB nextB;
};

struct list_buku {
    addressB first;
};

void createlistbuku(list_buku &L);
void insertlastbuku(list_buku &L, addressB P);
void deleteafterbuku(list_buku &L, addressB &P, addressB Q);
void deletelastbuku(list_buku &L, addressB &P);
void deletebuku(list_buku &L, addressB &P, string judul);
addressB allocate_buku(string judul);
addressB findelm(list_buku L, string x);
void printinfobuku(list_buku L);
int jumbuku(list_buku L);
