#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

using namespace std;


int main() {
    list L;
    createlist(L);
    list_buku Lb;
    char i;
    addressB K;

    cout<<"========== P R O G R A M  D A T A  B U K U =========="<<endl<<endl;
    cout<<"1. Tambah data penulis"<<endl;
    cout<<"2. Tambah data buku"<<endl;
    cout<<"3. Hapus data penulis"<<endl;
    cout<<"4. Hapus data buku"<<endl;
    cout<<"5. Tampilkan seluruh nama penulis dan karyanya"<<endl;
    cout<<"6. Cari detail penulis"<<endl;
    cout<<"7. Cari detail buku"<<endl;
    cout<<"8. Penulis dengan karya terbanyak."<<endl;
    cout<< "9. EXIT"<<endl<<endl;
    cout<<"====================================================="<<endl;
    cout<<endl<<"PILIH MENU : ";
    cin>>i;

    while (i != '9') {

        if (i == '1') {
            system("CLS");
            cout<<endl<<"         T A M B A H  D A T A  P E N U L I S         "<<endl;
            cout<<"====================================================="<<endl<<endl;

            cin.clear();
            cin.sync();
            string penulis, judul;
            int yangditulis;
            cout<< " Nama Penulis : ";
            getline(cin, penulis);
            cout<< " Jumlah buku yang ditulis : ";
            cin>>yangditulis;
            address P = allocate(penulis, yangditulis);
            insertfirstpenulis(L, P);
            createlistbuku(Lb);
            int i = 1;
            cout<<"Judul buku "<<i<< " : ";
            cin.ignore();
            getline(cin, judul);

            i=i+1;
            K = allocate_buku(judul);
            insertlastbuku(Lb, K);
            connect(L, penulis, Lb);
            while (i<=yangditulis) {
                cout<<"Judul buku "<<i<< " : ";
                getline(cin, judul);

                K = allocate_buku(judul);
                insertlastbuku(Lb, K);
                i++;
            }

            cout<<endl<<"Data berhasil ditambahkan!"<<endl<<endl<<"Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '2') {
            system("CLS");
            cout<<endl<<"            T A M B A H  D A T A  B U K U            "<<endl;
            cout<<"====================================================="<<endl<<endl;
            address P;
            addressB K;

            string judul, penulis;
            cin.clear();
            cin.sync();

            cout<<"Judul buku : ";
            getline(cin, judul);

            cout<<endl<<"Penulis : ";
            getline(cin, penulis);


            P = searchpen(L, penulis);

            if (P != NULL) {
                K = allocate_buku(judul);
                insertlastbuku(Lb, K);
                infoP(P).yangditulis++;
            } else {

                address Q = allocate(penulis, 1);
                insertfirstpenulis(L, Q);
                createlistbuku(Lb);
                K = allocate_buku(judul);
                insertlastbuku(Lb, K);
                connect(L, penulis, Lb);
            }
            cout<<endl<<"Data berhasil ditambahkan!"<<endl<<endl<<"Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '3') {
            system("CLS");
            cout<<endl<<"          H A P U S  D A T A  P E N U L I S          "<<endl;
            cout<<"====================================================="<<endl<<endl;
            string penulis;
            bool ada = false;
            cin.clear();
            cin.sync();
            cout<<"Data penulis yang akan dihapus : ";
            getline(cin, penulis);

            address P = searchpen(L, penulis);
            if (P != NULL) {
                if (prevP(P) == 0) {
                    deletefirstpenulis(L, P);
                } else if (nextP(P) == 0) {
                    deletelastpenulis(L, P);
                } else {
                    address Q = prevP(P);
                    deleteafterpenulis(L, P, Q);
                }
            }
            if (ada == true) {
                cout<<endl<<"Penghapusan berhasil!"<<endl;
            } else {
                cout<<"Maaf, tidak ada data yang dapat dihapus."<<endl;
            }
            cout<<endl<<endl<<"Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '4') {
            system("CLS");
            cout<<endl<<"             H A P U S  D A T A  B U K U             "<<endl;
            cout<<"====================================================="<<endl<<endl;
            cin.clear();
            cin.sync();
            string j;
            bool ada = false;
            cout<< "Masukkan judul buku yang ingin dihapus : ";
            getline(cin, j);

            address P = first(L);
            if (P != NULL) {
            while (P != 0) {
                addressB Q = nextB(P);
                if (info(Q).judul == j) {
                    deletefirstbuku(P, Lb, Q);
                    ada = true;
                    Q = nextB(Q);
                }

                while (Q != NULL) {
                    if (info(Q).judul == j) {
                        deletebuku(Lb, Q, j);
                        ada = true;
                        infoP(P).yangditulis--;
                    }
                    Q = nextB(Q);
                }
                P = nextP(P);
            }

            if (ada == true) {
                cout<<endl<<"Penghapusan berhasil!"<<endl;
            } else {
                cout<<"Maaf, tidak ada data yang dapat dihapus."<<endl;
            }
            }
            cout<<endl<<"Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '5') {
            system("CLS");
            cout<<endl<<"               D A T A  L E N G K A P               "<<endl;
            cout<<"====================================================="<<endl<<endl;
            showall(L);
            cout<<endl<< "Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '6') {
            system("CLS");
            cout<<"      P E N C A R I A N  D A T A  P E N U L I S      "<<endl;
            cout<<"====================================================="<<endl<<endl;
            string nama;
            cin.clear();
            cin.sync();
            cout<<"Masukkan nama penulis untuk menampilkan karyanya : ";
            getline(cin, nama);
            address P = searchpen(L, nama);
            if ( P != NULL) {
                showpenulis(L, P);
            } else {
                cout<<endl<<"Nama penulis tidak ditemukan."<<endl<<"Perhatikan penulisan nama dan huruf kapital. Pencarian ini bersifat 'case sensitive'"<<endl;
            }

            cout<<endl<< "Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '7') {
            system("CLS");
            cout<<"         P E N C A R I A N  D A T A  B U K U         "<<endl;
            cout<<"====================================================="<<endl<<endl;

            string b, arr[100];
            int i = 0;
            cin.clear();
            cin.sync();
            cout<<"Cari buku : ";
            getline(cin, b);

            address P = first(L);
            while (P != 0) {
                addressB Q = nextB(P);
                while (Q != 0) {
                    if (info(Q).judul == b) {
                        arr[i] = infoP(P).penulis;
                        i++;
                    }
                    Q = nextB(Q);
                }
                P = nextP(P);
            }
            if (i == 0) {
                cout<<"Maaf, rincian buku tidak ditemukan.";
            } else {
            cout<<"Buku '"<<b<<"' dikarang oleh "<<i<<" orang penulis yang tertera dibawah ini."<<endl;
            for (int j=0; j<i; j++) {
                cout<<j+1<<". "<<arr[j]<<endl;
            }
            }
            cout<<endl<< "Tekan ENTER untuk kembali ke menu.";
            getch();
        } else if (i == '8') {
            system("CLS");
            cout<<"     P E N U L I S  K A R Y A  T E R B A N Y A K     "<<endl;
            cout<<"====================================================="<<endl<<endl;
            address P = first(L);
            int sum = 0;
            string nama;
            while (P != 0) {
                if (infoP(P).yangditulis > sum) {
                    sum = infoP(P).yangditulis;
                    nama = infoP(P).penulis;
                }
                P = nextP(P);

            }
            if (sum != 0) {
                cout<<"Penulis dengan karya terbanyak adalah '"<<nama<<"' dengan total "<<sum<<" karya."<<endl;
            } else {
                cout<<"Maaf, belum ada data yang tersimpan"<<endl;
            }
            cout<<endl<< "Tekan ENTER untuk kembali ke menu.";
            getch();
        }
        system("CLS");
        cout<<"========== P R O G R A M  D A T A  B U K U =========="<<endl<<endl;
        cout<<"1. Tambah data penulis"<<endl;
        cout<<"2. Tambah data buku"<<endl;
        cout<<"3. Hapus data penulis"<<endl;
        cout<<"4. Hapus data buku"<<endl;
        cout<<"5. Tampilkan nama-nama penulis dan karyanya"<<endl;
        cout<<"6. Cari detail penulis"<<endl;
        cout<<"7. Cari detail buku"<<endl;
        cout<<"8. Penulis dengan karya terbanyak."<<endl;
        cout<<"9. EXIT"<<endl;
        cout<<"====================================================="<<endl<<endl;
        cout<<endl<<"PILIH MENU : ";
        cin>>i;
    }

    system("CLS");
    cout<<endl<<endl;
    cout<< "========================="<<endl;
    cout<< " T E R I M A  K A S I H "<<endl;
    cout<< " S A M P A I  J U M P A "<<endl;
    cout<<"========================="<<endl<<endl<<endl;

    cout<< "TUGAS BESAR ALGORITMA DAN STRUKTUR DATA"<<endl;
    cout<<"1. I Gusti Agung Istri Savitri Maharani (1303193085)"<<endl;
    cout<< "2. Eliza Fatrisia (1303190039)"<<endl;
    cout<< "Kelas IT - 43 - 03"<<endl<<endl;

    return 0;

}
