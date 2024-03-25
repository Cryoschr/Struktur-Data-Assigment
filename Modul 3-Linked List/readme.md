# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori


## Guided 
### 1. Single Linked List
```C++
#include <iostream>
using namespace std;

/// PROGRAM SINGLE LINKED LIST NON-CIRCULAR
// Deklarasi Struct Node
struct Node
{
    // komponen/member
    int data;
    Node *next;
};
Node *head;
Node *tail;
// Inisialisasi Node
void init()
{
    head = NULL;
    tail = NULL;
}
// Pengecekan
bool isEmpty()
{
    if (head == NULL)
        return true;
    else
        return false;
}
// Tambah Depan
void insertDepan(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        baru->next = head;
        head = baru;
    }
}
// Tambah Belakang
void insertBelakang(int nilai)
{
    // Buat Node baru
    Node *baru = new Node;
    baru->data = nilai;
    baru->next = NULL;
    if (isEmpty() == true)
    {
        head = tail = baru;
        tail->next = NULL;
    }
    else
    {
        tail->next = baru;
        tail = baru;
    }
}
// Hitung Jumlah List
int hitungList()
{
    Node *hitung;
    hitung = head;
    int jumlah = 0;
    while (hitung != NULL)
    {
        jumlah++;
        hitung = hitung->next;
    }
    return jumlah;
}
// Tambah Tengah
void insertTengah(int data, int posisi)
{
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi diluar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        Node *baru, *bantu;
        baru = new Node();
        baru->data = data;
        // tranversing
        bantu = head;
        int nomor = 1;
        while (nomor < posisi - 1)
        {
            bantu = bantu->next;
            nomor++;
        }
        baru->next = bantu->next;
        bantu->next = baru;
    }
}
// Hapus Depan
void hapusDepan()
{
    Node *hapus;
    if (isEmpty() == false)
    {
        if (head->next != NULL)
        {
            hapus = head;
            head = head->next;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Belakang
void hapusBelakang()
{
    Node *hapus;
    Node *bantu;
    if (isEmpty() == false)
    {
        if (head != tail)
        {
            hapus = tail;
            bantu = head;
            while (bantu->next != tail)
            {
                bantu = bantu->next;
            }
            tail = bantu;
            tail->next = NULL;
            delete hapus;
        }
        else
        {
            head = tail = NULL;
        }
    }
    else
    {
        cout << "List kosong!" << endl;
    }
}
// Hapus Tengah
void hapusTengah(int posisi)
{
    Node *hapus, *bantu, *bantu2;
    if (posisi < 1 || posisi > hitungList())
    {
        cout << "Posisi di luar jangkauan" << endl;
    }
    else if (posisi == 1)
    {
        cout << "Posisi bukan posisi tengah" << endl;
    }
    else
    {
        int nomor = 1;
        bantu = head;
        while (nomor <= posisi)
        {
            if (nomor == posisi - 1)
            {
                bantu2 = bantu;
            }
            if (nomor == posisi)
            {
                hapus = bantu;
            }
            bantu = bantu->next;
            nomor++;
        }
        bantu2->next = bantu;
        delete hapus;
    }
}
// Ubah Depan
void ubahDepan(int data)
{
    if (isEmpty() == false)
    {
        head->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Tengah
void ubahTengah(int data, int posisi)
{
    Node *bantu;
    if (isEmpty() == false)
    {
        if (posisi < 1 || posisi > hitungList())
        {
            cout << "Posisi di luar jangkauan" << endl;
        }
        else if (posisi == 1)
        {
            cout << "Posisi bukan posisi tengah" << endl;
        }
        else
        {
            bantu = head;
            int nomor = 1;
            while (nomor < posisi)
            {
                bantu = bantu->next;
                nomor++;
            }
            bantu->data = data;
        }
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Ubah Belakang
void ubahBelakang(int data)
{
    if (isEmpty() == false)
    {
        tail->data = data;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
// Hapus List
void clearList()
{
    Node *bantu, *hapus;
    bantu = head;
    while (bantu != NULL)
    {
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    head = tail = NULL;
    cout << "List berhasil terhapus!" << endl;
}
// Tampilkan List
void tampil()
{
    Node *bantu;
    bantu = head;
    if (isEmpty() == false)
    {
        while (bantu != NULL)
        {
            cout << bantu->data << ends;
            bantu = bantu->next;
        }
        cout << endl;
    }
    else
    {
        cout << "List masih kosong!" << endl;
    }
}
int main()
{
    init();
    insertDepan(3);
    tampil();
    insertBelakang(5);
    tampil();
    insertDepan(2);
    tampil();
    insertDepan(1);
    tampil();
    hapusDepan();
    tampil();
    hapusBelakang();
    tampil();
    insertTengah(7, 2);
    tampil();
    hapusTengah(2);
    tampil();
    ubahDepan(1);
    tampil();
    ubahBelakang(8);
    tampil();
    ubahTengah(11, 2);
    tampil();
    return 0;
}
```
#### Output:


### 2. Double Linked List
```C++
#include <iostream>
using namespace std;

int main(){
    //Deklarasi variabel
    int maks, a, i=1, lokasi;

    //Input panjang array
    cout<<"Masukkan panjang array: ";
    cin>>a;
    
    //Deklarasi array
    int array[a];
    cout<<"Masukkan "<<a<<" angka\n";
    for(i=0;i<a;i++){
        cout<<"Array ke-"<<(i)<<": ";
        cin>>array[i];
    }
    
    //Mencari nilai maks
    maks=array[0];
    for(int i=0;i<a;i++){
        if(array[i]>maks){
            maks=array[i];
            lokasi=i;
        }
    }

    //Menampilkan nilai maks dan lokasi array
    cout<<"Nilai maksimum adalah "<<maks<<" berada di array ke-"<<lokasi<<endl;
    return 0;
}
```
#### Output:


## Unguided 
### 1. Soal mengenai Single Linked List
Buatlah program menu Single Linked List Non-Circular untuk menyimpan Nama dan usia mahasiswa, dengan menggunakan inputan dari user. Lakukan operasi berikut:
a. Masukkan data sesuai urutan berikut. (Gunakan insert depan, belakang atau tengah). Data pertama yang dimasukkan adalah nama dan usia anda.

[Nama_anda] [Usia_anda]
John 19
Jane 20
Michael 18
Yusuke 19
Akechi 20
Hoshino 18
Karin 18

b. Hapus data Akechi
c. Tambahkan data berikut diantara John dan Jane : Futaba 18
d. Tambahkan data berikut diawal : Igor 20
e. Ubah data Michael menjadi : Reyn 18
f. Tampilkan seluruh data

```C++
#include <iostream>
using namespace std;

int main(){
    //Deklarasi variabel
    int genap;
    //Deklarasi array
    int array[10]={1,2,3,4,5,6,7,8,9,10};

    //Menampilkkan array
    cout<<"Data Array   :";
    for (int i=0; i<10; i++){
        cout << " "<<array[i];
    }
    cout<<endl;

    //Mencari array dengan nomor genap
    cout<<"Nomor Genap  :";
    for (int i=0; i<10; i++){
        if(array[i] % 2 == 0){
            cout<<" "<<array[i];
        }
    }
    cout<<endl;
    
    //Mencari array dengan nomor ganjil
    cout<<"Nomor Ganjil :";
    for (int i=0; i<10; i++){
        if(array[i] % 2 != 0){
            cout<<" "<<array[i];
        }
    }
    return 0;
}
```
#### Output:


### 2. Soal mengenai Double Linked List
Modifikasi Guided Double Linked List dilakukan dengan penambahan operasi untuk menambah data, menghapus, dan update di tengah / di urutan tertentu yang diminta. Selain itu, buatlah agar tampilannya menampilkan Nama produk dan harga.

Nama Produk Harga
Originote 60.000
Somethinc 150.000
Skintific 100.000
Wardah 50.000
Hanasui 30.000

Case:
1. Tambahkan produk Azarine dengan harga 65000 diantara
Somethinc dan Skintific
2. Hapus produk wardah
3. Update produk Hanasui menjadi Cleora dengan harga 55.000
4. Tampilkan menu seperti dibawah ini
Toko Skincare Purwokerto
1. Tambah Data
2. Hapus Data
3. Update Data
4. Tambah Data Urutan Tertentu
5. Hapus Data Urutan Tertentu
6. Hapus Seluruh Data
7. Tampilkan Data
8. Exit
Pada menu 7, tampilan akhirnya akan menjadi seperti dibawah
ini :

Nama Produk Harga
Originote 60.000
Somethinc 150.000
Azarine 65.000
Skintific 100.000
Cleora 55.000

```C++
#include <iostream>
using namespace std;

int main(){
    int a,b,c;

    //Input panjang array
    cout<<"Masukkan Panjang Array 3 Dimensi: "<<endl;
    cout<<"[][][]\n";
    cin>>a;
    cout<<"[" <<a<< "][][]\n";
    cin>>b;
    cout<<"[" <<a<< "][" <<b<< "][]\n";
    cin>>c;
    //Menampilkan panjang array
    cout<<"Array[" <<a<< "][" <<b<< "][" <<c<< "]\n";
    cout<<endl;

    //Deklarasi array
    int array[a][b][c];
    //Input array
    cout<<"Masukkan Nilai Array : "<<endl;
    for (int x=0; x<a; x++){
        for (int y=0; y<b; y++){
            for (int z=0; z<c; z++){
                cout<<"Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin>>array[x][y][z];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    //Menampikan array
    cout<<"Tampilan Array 3 Dimensi : "<<endl;
    for (int x=0; x<a; x++){
        for (int y=0; y<b; y++){
            for (int z=0; z<c; z++){
                cout<<array[x][y][z]<<ends;
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}
```
#### Output:


## Kesimpulan
Array merupakan struktur data penting untuk menyimpan data terstruktur. Jenis array dikategorikan berdasarkan dimensinya, yaitu array satu dimensi, dua dimensi, dan multidimensi. Array satu dimensi digunakan untuk menyimpan daftar data sederhana, array dua dimensi cocok untuk tabel, matriks, sedangkan array multidimensi digunakan untuk data kompleks dengan struktur multidimensi. Memilih jenis array yang tepat membantu dalam mengelola data dan meningkatkan efisiensi program. Array menawarkan akses data yang cepat dan mudah, serta dapat digunakan dalam berbagai operasi.


## Referensi
[1] MODUL 2-ARRAY
[2] Malik, D. S. (2023). C++ programming. Cengage Learning, EMEA.
