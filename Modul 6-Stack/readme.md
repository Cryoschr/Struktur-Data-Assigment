# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
Stack atau tumpukan adalah suatu stuktur data yang penting dalam pemrograman dengan metode pemrosesan yang bersifat LIFO (Last In First Out) dimana objek/benda yang terakhir masuk ke dalam stack akan menjadi benda pertama yang dikeluarkan dari stack. Dengan model demikian, maka hanya bagian paling atas saja dari stack (TOP) yang bisa di akses.

Adapun operasi-operasi/fungsi yang dapat dilakukan pada stack adalah sebagai berikut :
1) Push : digunakan untuk menambah item pada stack pada tumpukan paling atas.
2) Pop : digunakan untuk mengambil item pada stack pada tumpukan paling atas.
3) Clear : digunakan untuk mengosongkan stack.
4) IsEmpty : fungsi yang digunakan untuk mengecek apakah stack sudah kosong.
5) IsFull : fungsi yang digunakan untuk mengecek apakah stack sudah penuh. [1]
6) Top : Mendapatkan nilai atau melihat elemen teratas pada tumpukan tanpa menghapusnya.
7) Size : Mengembalikan jumlah elemen yang ada dalam tumpukan.
8) Peek : Melihat nilai atau elemen pada posisi tertentu dalam tumpukan tanpa menghapusnya.
9) Search : Mencari keberadaan elemen tertentu dalam tumpukan.[2]



## Guided 
### 1. Stack
```C++
#include <iostream>
using namespace std;

//inisialisasi dan deklarasi
string arrayBuku [5];
int maksimal = 5, top = 0;

//cek apakah penuh
bool isFull(){
    return (top == maksimal);
}

//cek apakah kosong
bool isEmpty(){
    return (top == 0);
}

//memasukkan data
void pushArrayBuku(string data){
    if (isFull()){
        cout<<"Data telah penuh"<<endl;
    }else{
        arrayBuku[top]=data;
        top++;
    }
}

//mengeluarkam data
void popArrayBuku(){
    if (isEmpty()){
        cout<<"Tidak ada data yang dihapus"<<endl;
    }else{
        arrayBuku[top-1]="";
        top--;
    }
}

//melihat data
void peekArrayBuku(int posisi){
    if (isEmpty()){
        cout<<"Tidak ada data yang dilihat"<<endl;
    }else{
        int index=top;
        for (int i=1;i<=posisi;i++){
            index--;
        }
        cout<<"Posisi ke "<<posisi<<" adalah "<<arrayBuku[index]<<endl;
    }
}

int countStack(){
    return top;
}

//mengubah data
void changeArrayBuku(int posisi, string data){
    if (posisi>top){
        cout<<"Posisi melebihi data yang ada"<<endl;
    }else{
        int index=top;
        for(int i=1;i<=posisi;i++){
            index--;
        }
        arrayBuku[index]=data;
    }
}

//menghapus semua data
void destroyArrayBuku(){
    for (int i=top;i>=0;i--){
        arrayBuku[i]="";
    }
    top=0;
}

//menampilkan
void cetakArrayBuku(){
    if (isEmpty()){
        cout<<"Tidak ada data yang dicetak"<<endl;
    }else{
        for (int i=top-1;i>=0;i--){
            cout<<arrayBuku[i]<<endl;
        }
    }
}

int main(){
    pushArrayBuku("Kalkulus");
    pushArrayBuku("Struktur Data");
    pushArrayBuku("Matematika Diskrit");
    pushArrayBuku("Dasar Multimedia");
    pushArrayBuku("Inggris");

    cetakArrayBuku();
    cout<<"\n";

    cout<<"Apakah data stack penuh? "<<isFull()<<endl;
    cout<<"Apakah data stack kosong? "<<isEmpty()<<endl;

    peekArrayBuku(2);
    popArrayBuku();

    cout<<"Banyaknya Data = "<<countStack()<<endl;

    changeArrayBuku(2, "Bahasa Jerman");
    cetakArrayBuku();

    cout<<"\n";

    destroyArrayBuku();
    cout << "Jumlah data setelah dihapus: " << top << endl;
    cetakArrayBuku();

return 0;
}
```
#### Output:
![Screenshot 2024-05-05 224414](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/90f09502-1764-49e7-952e-4b629a14abb9)
Program ini menunjukkan implementasi stack (tumpukan) sederhana dalam bahasa C++. Stack diimplementasikan menggunakan array dengan beberapa fungsi untuk melakukan operasi stack dasar.

Stack diinisialisasi dengan kapasitas 5 elemen dan fungsi-fungsi seperti push(), pop(), peek(), count(), change(), destroy(), dan cetak() didefinisikan untuk memanipulasi dan menampilkan elemen dalam stack.

Fungsi main() mendemonstrasikan penggunaan fungsi-fungsi stack dengan menambahkan 5 buah buku ke stack, menampilkan isi stack, mengecek status stack (penuh/kosong), melihat elemen tertentu, menghapus elemen teratas, mengubah elemen, menghapus semua elemen, dan menampilkan kembali isi stack yang kosong.

Program ini memberikan contoh dasar implementasi stack dan dapat dimodifikasi untuk kebutuhan aplikasi yang berbeda dengan menambahkan fungsi-fungsi lain atau mengubah struktur data yang digunakan.



## Unguided
### 1. Buatlah program untuk menentukan apakah kalimat tersebut yang diinputkan dalam program stack adalah palindrom/tidak. Palindrom kalimat yang dibaca dari depan dan belakang sama. Jelaskan bagaimana cara kerja programnya.
![Screenshot 2024-05-05 232433](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/80b36eb0-1c66-4d10-93e3-48e8518388f8)

```C++

```
#### Output:

### 2. Buatlah program untuk melakukan pembalikan terhadap kalimat menggunakan stack dengan minimal 3 kata. Jelaskan output program dan source codenya beserta operasi/fungsi yang dibuat?
![Screenshot 2024-05-05 232521](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/d385861e-9a75-4d72-b0a1-f3f0cf9b8c6f)

#### Output:
```C++

```

## Kesimpulan
Stack atau tumpukan adalah struktur data yang penting dalam pemrograman dengan metode LIFO (Last In First Out). Elemen yang terakhir masuk ke dalam stack akan menjadi yang pertama kali dikeluarkan. Stack hanya dapat diakses dari bagian atasnya (TOP).

## Referensi
[1] Sihombing, J. (2019). Penerapan Stack Dan Queue Pada Array Dan Linked List Dalam Java. INFOKOM (Informatika & Komputer), 7(2), 15-24.

[2] 
