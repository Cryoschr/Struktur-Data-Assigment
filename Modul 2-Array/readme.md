# <h1 align="center">Laporan Praktikum Modul Tipe Data</h1>
<p align="center">Irshad Benaya Fardeca</p>

# Dasar Teori
Array adalah kumpulan dari sejumlah tetap komponen yang semuanya memiliki tipe data yang sama. Array satu dimensi adalah array dimana komponen-komponennya disusun dalam bentuk daftar.[2] Array terdiri dari satu dimensi, dua dimensi atau lebih.
Berikut adalah beberapa jenis array:

1. Array Satu Dimensi
Kumpulan data dari jenis yang sama yang disusun dalam satu baris atau satu dimensi disebut array satu dimensi. Setiap elemen dalam array memiliki indeks atau nomor yang dapat diakses. Indeks dimulai dari 0 dan berakhir pada jumlah elemen dikurangi satu. Untuk ilustrasi, sebuah array satu dimensi yang terdiri dari bilangan bulat {1, 2, 3, 4, 5} memiliki lima elemen. Indeks 0 menunjukkan elemen pertama, indeks 1 menunjukkan elemen kedua, dan seterusnya hingga indeks 4 menunjukkan elemen kelima.

2. Array Dua Dimensi
Array dua dimensi adalah variable yang terdiri dari kumpulan array satu dimensi dengan tipe yang sama yang disusun dalam baris dan kolom. Indeks baris menunjukkan posisi elemen dalam baris, dan indeks kolom menunjukkan posisi elemen dalam kolom.

3. Array Multidimensi
Meskipun mereka mirip dengan array satu dimensi dan dua dimensi, array multidimensi memiliki kapasitas memori yang lebih besar. Mereka digunakan untuk menunjukkan array dengan lebih dari dua dimensi atau dengan lebih dari dua indeks, seperti array tiga dimensi, empat dimensi, dan lima dimensi, dan seterusnya.[1]


## Guided 
### 1. Array Tiga Dimensi
```C++
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
```
#### Output:
![Screenshot 2024-03-19 214011](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/b0dbfe7c-c8f6-40bb-a720-03860f1857c7)
Program mendeklarasikan array yang berukuran 2 x 3 x 3. Program kemudian menggunakan tiga loop untuk meminta input pengguna untuk mengisi setiap elemen array. Looping akan berjalan sebanyak 2 x 3 x 3, sesuai dengan jumlah elemen total dalam array. Setelah input selesai, program menampilkan isi array menggunakan loop. Selanjutnya, program mencetak nilai yang tersimpan pada setiap elemen array. Isi array ditampilkan dalam bentuk matriks 2 x 3 x 3, dengan loop untuk mengakses elemen per elemen. Saat mencetak, program menambahkan karakter "ends" untuk mengatur jarak antar elemen, sehingga terbentuk tampilan matriks.

### 2. Mencari Nilai Maksimal Pada Array
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
![Screenshot 2024-03-19 214128](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/0b4be380-1efc-4b11-825c-a93eec64ce91)
Program ini menemukan nilai maksimum array dan menunjukkan lokasinya. Program menentukan variabel yang digunakan untuk menyimpan nilai maksimum, panjang array, dan lokasi. Kemudian, program meminta pengguna untuk memasukkan panjang dan nilai elemen array masing-masing. Kemudian, program menginisialisasi nilai maksimum dengan nilai elemen array pertama. Kemudian, program melakukan perulangan untuk setiap elemen array dan membandingkannya dengan nilai maksimum. Jika nilai elemen array lebih besar dari nilai maksimum, maka elemen array tersebut akan dihapus dari array. Selanjutnya Program menampilkan nilai maks dan lokasi array.


## Unguided 
### 1. Buatlah program untuk menampilkan Output seperti berikut dengan data yang diinputkan oleh user!
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
![Screenshot 2024-03-19 214543](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/a8ecc4de-4f87-4e67-b560-4185b641d804)
Program ini menunjukkan cara mencari nomor genap dan ganjil dalam sebuah array dengan mendeklarasikan variabel genap dan array dengan sepuluh elemen. Kemudian, program menampilkan seluruh elemen array dan menggunakan perulangan for untuk menemukan nomor genap. Di dalam perulangan, program mencari tahu apakah elemen dalam array saat ini habis dibagi 2. Jika hasilnya adalah ya, elemen tersebut akan ditampilkan. Untuk mencari nomor ganjil, program mencari apakah elemen dalam array saat ini tidak habis dibagi 2. Kemudian program menampilkan hasilnya.

### 2. Buatlah program Input array tiga dimensi (seperti pada guided) tetapi jumlah atau ukuran elemennya diinputkan oleh user!
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
![Screenshot 2024-03-19 215623](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/0af0bb53-7414-45e0-b48f-c32db5bfbab3)
Program ini menunjukkan cara membuat dan menggunakan array tiga dimensi. Ini meminta pengguna untuk memasukkan panjang dari ketiga dimensi array tersebut, kemudian mendeklarasikan array dengan ukuran yang sesuai dengan input pengguna. Setelah itu, program meminta pengguna untuk memasukkan nilai ke dalam setiap elemen array menggunakan tiga loop for yang bersarang, dan kemudian menampilkan isi dari seluruh array dalam matriks tiga dimensi di layar.

### 3. Buatlah program menu untuk mencari nilai Maksimum, Minimum dan Nilai rata – rata dari suatu array dengan input yang dimasukan oleh user!
```C++
#include <iostream>
using namespace std;

int main(){
    //Deklarasi variabel
    int menu,a,maks,min,i=1;
    float rata,total;

    //Input panjang array
    cout<<"Masukkan Panjang Array : ";
    cin>>a;

    //Deklarasi array
    int array[a];
 
    //Input array
    for (i=0; i<a; i++){
        cout<<"Array index ke-"<<i<<" = ";
        cin>>array[i];
    }
    cout<<endl;

    //Tampilan menu
    cout<<"     Menu\n";
    cout<<"1. Nilai Maksimum\n";
    cout<<"2. Nilai Minimum\n";
    cout<<"3. Nilai Rata-Rata\n";
    cout<<"Pilih Nomor : ";
    cin>>menu;


    switch (menu){
    case 1:
    //Mencari nilai maksimum array
        maks=array[0];
        for (i=0; i<a; i++){
            if(array[i]>maks){
                maks=array[i];
            }
        }
        cout<<"Nilai Maksimum = "<<maks;
    cout<<endl;
        break;

    case 2:
    //Mencari nilai minimum array
        min=array[0];
        for (i=0; i<a; i++){
            if(array[i]<min){
                min=array[i];
            }
        }
        cout<<"Nilai Minimum = "<<min;
    cout<<endl;
        break;

    case 3:
    //Mencari rata-rata array
        for (i=0; i<a; i++){
            total+=array[i];
        }
        rata=total/a;
        cout<<"Rata-Rata = "<<rata;
        cout<<endl;
        break;

    default:
        cout<<"Silahkan Coba Lagi :]";
    cout<<endl;
        break;
    }
    return 0;
}
```
#### Output:
![Screenshot 2024-03-19 222206](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/12477c7c-33c4-4792-a390-474091520cfc)
![Screenshot 2024-03-19 222502](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/376b4d3c-caf2-4c5b-b539-fed15d0fc763)
![Screenshot 2024-03-19 222242](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/ba5c4482-1c84-444a-9437-25997a48b555)
Program ini menghitung nilai maksimum, minimum, dan rata-rata dari sebuah array. Panjang array yang dimasukkan oleh user dan nilai-nilainya dimasukkan satu per satu. Kemudian, user dapat memilih menu untuk mencari nilai maksimum, minimum, atau rata-rata dan menampilkannya di layar.


## Kesimpulan
Array merupakan struktur data penting untuk menyimpan data terstruktur. Jenis array dikategorikan berdasarkan dimensinya, yaitu array satu dimensi, dua dimensi, dan multidimensi. Array satu dimensi digunakan untuk menyimpan daftar data sederhana, array dua dimensi cocok untuk tabel, matriks, sedangkan array multidimensi digunakan untuk data kompleks dengan struktur multidimensi. Memilih jenis array yang tepat membantu dalam mengelola data dan meningkatkan efisiensi program. Array menawarkan akses data yang cepat dan mudah, serta dapat digunakan dalam berbagai operasi.


## Referensi
[1] MODUL 2-ARRAY
[2] Malik, D. S. (2023). C++ programming. Cengage Learning, EMEA.
