# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>
<p align="center">S1-IF-11E</p>
<p align="center"> 2311102199</p>

# Dasar Teori
Kebalikan dari stack, queue (antrian) adalah suatu jenis struktur data yang dapat diproses dengan sifat FIFO (First In First Out), dimana elemen yang pertama kali masuk ke antrian akan keluar pertama kalinya. Ada
dua jenis operasi yang bias dilakukan di antrian : enqueue (memasukkan elemen baru ke dalam elemen) dan dequeue (adalah mengeluarkan satu elemen dari suatu antrian)
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



## Unguided
### 1. Ubahlah penerapan konsep queue pada bagian guided dari array menjadi linked list

```C++

```
#### Output:

### 2. Dari nomor 1 buatlah konsep antri dengan atribut Nama mahasiswa dan NIM Mahasiswa

```C++

```
#### Output:

## Kesimpulan

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.
[2] 
