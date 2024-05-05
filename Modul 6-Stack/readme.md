# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori


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

## Referensi

