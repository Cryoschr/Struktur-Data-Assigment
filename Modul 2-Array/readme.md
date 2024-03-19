# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori

Struktur data yang paling dasar adalah array, dan sebelum mempelajari struktur data lainnya, kita harus mempelajarinya terlebih dahulu. Berikut adalah beberapa jenis array:


1) Array Satu Dimensi
Kumpulan data dari jenis yang sama yang disusun dalam satu baris atau satu dimensi disebut array satu dimensi. Setiap elemen dalam array memiliki indeks atau nomor yang dapat diakses. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu. Untuk ilustrasi, sebuah array satu dimensi yang terdiri dari bilangan bulat {1, 2, 3, 4, 5} memiliki lima elemen. Indeks 0 menunjukkan elemen pertama, indeks 1 menunjukkan elemen kedua, dan seterusnya hingga indeks 4 menunjukkan elemen kelima.


2) Array Dua Dimensi
Array dua dimensi adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Indeks baris menunjukkan posisi elemen dalam baris, dan indeks kolom menunjukkan posisi elemen dalam kolom.


3) Array Multidimensi
Meskipun mereka mirip dengan array satu dimensi dan dua dimensi, array multidimensi memiliki kapasitas memori yang lebih besar. Mereka digunakan untuk menunjukkan array dengan lebih dari dua dimensi atau dengan lebih dari dua indeks, seperti array tiga dimensi, empat dimensi, dan lima dimensi, dan seterusnya.



## Guided 
### 1. Array Tiga Dimensi

#include <iostream>
using namespace std;

int main(){
    //Deklarasi array
    int arr[2][3][3];
    
    //Input elemen
    for(int x=0;x<2;x++){
        for(int y=0;y<3;y++){
            for(int z=0;z<3;z++){
                cout<<"Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin>>arr[x][y][z];
            }
        }
        cout<<endl;
    }

    //Output array
    for(int x=0;x<2;x++){
        for(int y=0;y<3;y++){
            for (int z=0;z<3;z++){
                cout<<"Data Array[" << x << "][" << y << "][" << z << "]= "<<arr[x][y][z]<<endl;
            }
        }
    }
    cout<<endl;

    //Tampilan array
    for(int x=0;x<2;x++){
        for(int y=0;y<3;y++){
            for (int z=0;z<3;z++){
                cout<<arr[x][y][z]<<ends;
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}

#### Output:
![Screenshot 2024-03-19 214011](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b0dbfe7c-c8f6-40bb-a720-03860f1857c7)


### 2. Mencari Nilai Maksimal Pada Array

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

#### Output:
![Screenshot 2024-03-19 214128](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/0b4be380-1efc-4b11-825c-a93eec64ce91)



## Unguided 
### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
![Screenshot 2024-03-19 220824](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/f4320902-3614-44e5-8aa6-ba846249b6ea)

#### Output:
![Screenshot 2024-03-19 214543](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/a8ecc4de-4f87-4e67-b560-4185b641d804)



### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!

#### Output:
![Screenshot 2024-03-19 215623](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/0af0bb53-7414-45e0-b48f-c32db5bfbab3)


### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!

#### Output:
![Screenshot 2024-03-19 222206](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/12477c7c-33c4-4792-a390-474091520cfc)
![Screenshot 2024-03-19 222502](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/376b4d3c-caf2-4c5b-b539-fed15d0fc763)
![Screenshot 2024-03-19 222242](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/ba5c4482-1c84-444a-9437-25997a48b555)

## Kesimpulan


## Referensi
