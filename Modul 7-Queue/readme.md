# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>
<p align="center">S1-IF-11E</p>
<p align="center"> 2311102199</p>

# Dasar Teori
Queue (antrian) adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kalinya. Ada
dua jenis operasi yang biasa dilakukan di antrian : enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian).

Sedangkan bentuk fungsi-fungsi queue dapat dilihat berikut ini :
1) Fungsi Initialize
2) Fungsi Is_Empty, yang antara lain digunakan untuk :
   a. Untuk memeriksa apakah Antrian sudah penuh atau belum
   b. Dengan cara memeriksa nilai Tail, jika Tail = -1 maka empty
   c. Tidak perlu memeriksa Head, karena Head adalah tanda untuk kepala antrian (elemen pertama dalam antrian) yan:g tidak akan berubah
3) Fungsi Is_Full, berfungsi untuk :
   a. Untuk mengecek apakah Antrian sudah penuh atau belum
   b. Dengan cara mengecek nilai Tail, jika Tail >= MAX-1 (karena MAX-1 adalah batas elemen array pada C) berarti sudah penuh
4) Fungsi Enqueue , dengan tujuan :
   a. Untuk menambahkan elemen ke dalam Antrian, penambahan elemen selalu ditambahkan di elemen paling belakang
   b. Penambahan elemen selalu menggerakan variabel Tail dengan cara increment counter Tail.
6) Fungsi Dequeue :
   a. Digunakan untuk menghapus elemen terdepan/pertama dari Antrian21
   b. Dengan cara mengurangi counter Tail dan menggeser semua elemen antrian kedepan.
   c. Penggeseran dilakukan dengan menggunakan looping
7) Fungsi Tampil , yang berfungsi untuk menampilkan nilai-nilai elemen dalam Antrian dam menggunakan looping dari head samapai tail. [1]

## Guided 
### 1. Queue
```C++
#include <iostream>
using namespace std;

const int maksimalQueue = 5; // Maksimal antrian
int front = 0; // Penanda antrian
int back = 0; // Penanda
string queueTeller[5]; // Fungsi pengecekan

bool isFull() { // Pengecekan antrian penuh atau tidak
    if (back == maksimalQueue) {
        return true; // =1
    } else {
        return false;
    }
}

bool isEmpty() { // Antriannya kosong atau tidak
    if (back == 0) {
        return true;
    } else {
        return false;
    }
}

void enqueueAntrian(string data) { // Fungsi menambahkan antrian
    if (isFull()) {
        cout << "Antrian penuh" << endl;
    } else {
        
    if (isEmpty()) { // Kondisi ketika queue kosong
        queueTeller[0] = data;
        front++;
        back++;
    } else { // Antrianya ada isi
        queueTeller[back] = data;
        back++;
        }
    }
}

void dequeueAntrian() { // Fungsi mengurangi antrian
    if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
        queueTeller[i] = queueTeller[i + 1];
        }
        back--;
    }
}

int countQueue() { // Fungsi menghitung banyak antrian
    return back;
    }

void clearQueue() { // Fungsi menghapus semua antrian
        if (isEmpty()) {
        cout << "Antrian kosong" << endl;
    } else {
        for (int i = 0; i < back; i++) {
        queueTeller[i] = "";
        }
        back = 0;
        front = 0;
    }
}

void viewQueue() { // Fungsi melihat antrian
    cout << "Data antrian teller:" << endl;
    for (int i = 0; i < maksimalQueue; i++) {
        if (queueTeller[i] != "") {
            cout << i + 1 << ". " << queueTeller[i] << endl;
        } else {
            cout << i + 1 << ". (kosong)" << endl;
        }
    }
}


int main() {

enqueueAntrian("Andi");
enqueueAntrian("Maya");
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;

dequeueAntrian();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;

clearQueue();
viewQueue();
cout << "Jumlah antrian = " << countQueue() << endl;

return 0;
}
```
#### Output:
![Screenshot 2024-05-15 210217](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/e6b3d351-3e14-44ff-a993-07b4f085b923)
Program ini mensimulasikan sistem antrian untuk teller. Program ini mendefinisikan fungsi untuk menambah (enqueue), menghapus (dequeue), memeriksa penuh dan kosong, menghitung jumlah elemen, dan menampilkan isi antrian. Program ini menggunakan array string untuk menyimpan elemen antrian dan variabel penunjuk untuk melacak posisi depan dan belakang antrian. Program ini juga mendefinisikan konstanta untuk menentukan kapasitas maksimum antrian. Fungsi utama mendemonstrasikan penggunaan fungsi-fungsi antrian dengan menambahkan dua pelanggan, "Andi" dan "Maya", ke antrian, menampilkan antrian dan ukurannya, menghapus satu pelanggan, memperbarui tampilan dan ukuran, dan terakhir mengosongkan antrian untuk menunjukkan status kosongnya.


## Unguided
### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++
//Irshad Benaya Fardeca
//2311102199

#include <iostream>
using namespace std;

//deklarasi
struct antrianTeller{
  string data;

  antrianTeller *next;
};

//maks antrian
int maksimalAntrianTeller = 5;
antrianTeller *head, *tail, *cur, *del, *newNode;

//menghitung banyak antrian
int countQueue(){
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

//mengecek apakah penuh
bool isFull(){
  if( countQueue() == maksimalAntrianTeller ){
    return true;
  }else{
    return false;
  }
}

//mengecek apakah kosong
bool isEmpty(){
  if( countQueue() == 0 ){
    return true;
  }else{
    return false;
  }
}

//memasukkan kedalam antrian
void enqueueAntrian(string data){
  if( isFull() ){
    cout << "Antrian Penuh!" << endl;
  }else{
    
    if( isEmpty() ){
      head = new antrianTeller();
      head->data = data;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianTeller();
      newNode->data = data;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

//mengluarkan darri antrian
void dequeueAntrian(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

//menghapus semua antrian
void clearQueue(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}

//menampilkan antrian
void viewQueue(){
  cout << "Data Antrian Teller : " << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianTeller ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->data << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }
      nomor++;
    }
}


int main(){

  enqueueAntrian("Andi");
  enqueueAntrian("Maya");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;


return 0;
}
```
#### Output:
![Screenshot 2024-05-19 191325](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/a9391e8c-d109-4256-a036-8d1c848cfc63)
Kode C++ ini mensimulasikan sistem antrian untuk teller. Kode ini mendefinisikan struktur bernama antrianTeller untuk mewakili setiap pelanggan, yang berisi nama mereka (data) dan pointer (next) untuk menghubungkan mereka dalam antrian. Program ini menetapkan ukuran antrian maksimum (maksimalAntrianTeller) dan menggunakan fungsi untuk mengelola antrian:

countQueue(): Menghitung jumlah pelanggan yang sedang menunggu.
isFull(): Memeriksa apakah antrian sudah mencapai kapasitasnya.
isEmpty(): Memastikan apakah antrian kosong.
enqueueAntrian(string data): Menambahkan nama pelanggan baru (data) ke bagian belakang antrian, menangani skenario antrian penuh dan kosong.
dequeueAntrian(): Menghapus pelanggan di depan (yang dilayani), menangani kasus antrian kosong.
clearQueue(): Mengosongkan seluruh antrian dengan iterasi dan menghapus setiap pelanggan.
viewQueue(): Menampilkan isi antrian, menunjukkan posisi kosong jika ada.

Fungsi main mendemonstrasikan fungsi-fungsi ini dengan menambahkan pelanggan, melihat antrian dan ukurannya, menghapus pelanggan, memperbarui tampilan dan ukuran, dan terakhir mengosongkan antrian untuk menunjukkan status kosongnya.

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++
//Irshad Benaya Fardeca
//2311102199

#include <iostream>
using namespace std;

//deklarasi
struct antrianMahasiswa{
  string nama;
  string nim;

  antrianMahasiswa *next;
};

//maks data
int maksimalAntrianMahasiswa = 5;
antrianMahasiswa *head, *tail, *cur, *del, *newNode;

//menghitung data
int countQueue(){
  if( head == NULL ){
    return 0;
  }else{
    int banyak = 0;
    cur = head;
    while( cur != NULL ){
      cur = cur->next;
      banyak++;
    }
    return banyak;
  }
}

//mengecek data apakah penuh
bool isFull(){
  if( countQueue() == maksimalAntrianMahasiswa ){
    return true;
  }else{
    return false;
  }
}

//mengecek data apakah kosong
bool isEmpty(){
  if( countQueue() == 0 ){
    return true;
  }else{
    return false;
  }
}

//memasukkan data ke dalam queue
void enqueueAntrian(string nama, string nim){
  if( isFull() ){
    cout << "Antrian Penuh" << endl;
  }else{
    
    if( isEmpty() ){
      head = new antrianMahasiswa();
      head->nama = nama;
      head->nim = nim;
      head->next = NULL;
      tail = head;
    }else{
      newNode = new antrianMahasiswa();
      newNode->nama = nama;
      newNode->nim = nim;
      newNode->next = NULL;
      tail->next = newNode;
      tail = newNode;
    }

  }

}

//mengeluarkan data dari queue
void dequeueAntrian(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    del = head;
    head = head->next;
    del->next = NULL;
    delete del;
  }
}

//menghapus semua data
void clearQueue(){
  if( isEmpty() ){
    cout << "Antrian kosong" << endl;
  }else{
    cur = head;
    while( cur != NULL ){
      del = cur;
      cur = cur->next;
      del->next = NULL;
      delete del;
    }
    head = NULL;
    tail = NULL;
  }
}

//menampilkan queue
void viewQueue(){
  cout << "Daftar Antrian Mahasiswa : " << endl;
    cur = head;
    int nomor = 1;
    while( nomor <= maksimalAntrianMahasiswa ){
      
      if( cur != NULL ){
        cout << nomor << ". " << cur->nama << "_" << cur->nim << endl;
        cur = cur->next;
      }else{
        cout << nomor << ". " << "(kosong)" << endl;
      }
      nomor++;
    }
}


int main(){

  enqueueAntrian("Maya", "2311102188");
  enqueueAntrian("Sela", "2311102189");
  enqueueAntrian("Andi", "2311102190");
  enqueueAntrian("Irshad", "2311102199");
  enqueueAntrian("Ani", "231103288");
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  dequeueAntrian();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;

  clearQueue();
  viewQueue();
  cout << "Jumlah antrian = " << countQueue() << endl;


return 0;
}
```
#### Output:
![Screenshot 2024-05-19 213412](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/315c6f0e-034b-4c6c-beb5-7f2059c4ff85)
Program ini mensimulasikan sistem antrian untuk mengelola mahasiswa yang ingin mengurus sesuatu, seperti mengurus administrasi atau mengikuti kelas. Program ini menggunakan struktur data antrian untuk menyimpan informasi mahasiswa dan fungsi-fungsi untuk mengelola antrian. Fungsi-fungsi ini meliputi:

countQueue(): Menghitung jumlah mahasiswa yang sedang dalam antrian.
isFull(): Memeriksa apakah antrian sudah penuh atau belum.
isEmpty(): Memastikan apakah antrian kosong.
enqueueAntrian(string nama, string nim): Menambahkan mahasiswa baru ke bagian belakang antrian.
dequeueAntrian(): Menghapus mahasiswa di depan (yang dilayani), menangani kasus antrian kosong.
clearQueue(): Mengosongkan seluruh antrian dengan iterasi dan menghapus setiap mahasiswa.
viewQueue(): Menampilkan isi antrian, menunjukkan posisi kosong jika ada.
Fungsi utama (main) mendemonstrasikan fungsi-fungsi ini dengan menambahkan mahasiswa, melihat antrian dan ukurannya, menghapus mahasiswa, memperbarui tampilan dan ukuran, dan terakhir mengosongkan antrian untuk menunjukkan status kosongnya.


## Kesimpulan
Queue atau antrian merupakan struktur data yang mengikuti prinsip FIFO (First In First Out), di mana elemen yang pertama masuk akan keluar terlebih dahulu. Secara keseluruhan, queue dengan linked list cocok untuk skenario di mana ukuran queue tidak diketahui atau perlu fleksibel. Namun, jika akses acak cepat menjadi prioritas utama, implementasi array mungkin lebih cocok.

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.

