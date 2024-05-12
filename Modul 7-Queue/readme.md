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

```
#### Output:



## Unguided
### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.

```C++

```
#### Output:

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?

```C++

```
#### Output:

## Kesimpulan

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.
[2] 
