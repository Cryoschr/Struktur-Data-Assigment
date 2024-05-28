# <h1 align="center">Laporan Praktikum Modul Stack</h1>
<p align="center">Irshad Benaya Fardeca</p>
<p align="center">S1-IF-11E</p>
<p align="center"> 2311102199</p>

# Dasar Teori

## Guided 
### 1. Buatlah sebuah project dengan menggunakan sequential search sederhana untuk melakukan pencarian data.
```C++
#include <iostream>
using namespace std;

int main(){

    //inisialisasi dan deklarasi
    int n = 10;
    int data[n] = {9, 4, 1, 7, 5, 12, 4, 13, 4, 10};
    int cari = 10;
    bool ketemu = false;
    int i;

    // algoritma Sequential Search
    for (i = 0; i < n; i++)
    {
        if (data[i] == cari)
        {
            ketemu = true;
            break;
        }
    }

    cout << "\t Program Sequential Search Sederhana\n " << endl;
    cout<< "data: {9, 4, 1, 7, 5, 12, 4, 13, 4, 10}" << endl;
    
    if (ketemu){
        cout << "\n angka " << cari << " ditemukan pada indeks ke -" << i << endl;
    }else{
        cout << cari << " tidak dapat ditemukan pada data." << endl;
    }
return 0;
}
```
#### Output:
![Screenshot 2024-05-22 211346](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/c76b5156-adf1-47a8-b71b-458320bc1f23)
Program menerapkan algoritma sequential search yang sederhana untuk menemukan nilai tertentu (cari) dalam array data yang diberikan (data). Algoritma ini bekerja dengan cara mengiterasi melalui array, membandingkan setiap elemen dengan nilai pencarian. Jika nilai pencarian ditemukan, indeksnya disimpan dan pencarian dihentikan. Jika nilai pencarian tidak ditemukan, program menunjukkan bahwa nilai tersebut tidak ada dalam data.

### 2. Buatlah sebuah project untuk melakukan pencarian data dengan menggunakan Binary Search.
```C++
#include <iostream>
#include <iomanip>
using namespace std;

//inisialisai dan deklarasi
int arrayData[7] = {1,8,2,5,4,9,7};
int cari;

//selection sort
void selection_sort(int arr[], int n) {
    int temp, min;
    for (int i = 0; i < n - 1; i++) {
        min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
            min = j;
            }
        }
        // Tukar elemen
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

//binary search
void binary_search(int arr[], int n, int target){
    int awal = 0, akhir = n-1, tengah, b_flag = 0;

    while (b_flag == 0 && awal <= akhir){
        tengah = (awal + akhir) / 2;
        if (arr[tengah] == target){
            b_flag = 1;
            break;
        }else if (arr[tengah] < target){
            awal = tengah + 1;
        }else{
            akhir = tengah - 1;
        }
    }

    if (b_flag == 1){
        cout << "\nData ditemukan pada index ke- " << tengah << endl;
    }else{
        cout << "\nData tidak ditemukan\n";
    }
}

int main() {

    cout << "\tBINARY SEARCH" << endl;
    cout << "\nData awal: ";

    // Tampilkan data awal
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;

    //memasukkan data
    cout << "\nMasukkan data yang ingin Anda cari: ";
    cin >> cari;

    // Urutkan data dengan selection sort
    selection_sort(arrayData, 7);
    cout << "\nData diurutkan: ";

    // Tampilkan data setelah diurutkan
    for (int x = 0; x < 7; x++) {
        cout << setw(3) << arrayData[x];
    }
    cout << endl;

    // Lakukan binary search
    binary_search(arrayData, 7, cari);
return 0;
}
```
#### Output:
![Screenshot 2024-05-22 211547](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/2be8d270-0adf-47b7-9e6f-0c1bffbb7405)
Program ini menunjukkan contoh implementasi binary search untuk menemukan elemen tertentu dalam array yang telah diurutkan menggunakan algoritma selection sort. Program ini dimulai dengan mendefinisikan array data dan variabel untuk menyimpan nilai yang ingin dicari. Fungsi selection_sort kemudian digunakan untuk mengurutkan array data. Fungsi binary_search melakukan pencarian biner dengan membagi array menjadi dua bagian secara berulang dan membandingkan nilai target dengan elemen di tengah array. Jika nilai target ditemukan, indeksnya akan ditampilkan. Jika tidak ditemukan, pesan "Data tidak ditemukan" akan ditampilkan.


## Unguided
### 1. Buatlah sebuah program untuk mencari sebuah huruf pada sebuah kalimat yang sudah di input dengan menggunakan Binary Search!
```C++
//Irshad Benaya Fardeca
//2311102199
#include <iostream>
#include <cstring>

using namespace std;

//prosedur binary search
void binarySearch(char kalimat[], char target, int n) {
  int awal = 0, akhir = n - 1, index = -1;

  while (awal <= akhir) {
    int tengah = awal + (akhir - awal) / 2;

    if (kalimat[tengah] == target) {
        index = tengah;
        break;
    } else if (kalimat[tengah] < target) {
        awal = tengah + 1;
    } else {
        akhir = tengah - 1;
    }
  }

  if (index == -1) {
      cout << "Karakter '" << target << "' tidak ditemukan." << endl;
  } else {
      cout << "Karakter '" << target << "' ditemukan pada indeks " << index << endl;
  }
}

int main() {

  //deklarasi
  char kalimat[100];
  char target;
  
  //input kalimat
  cout << "Masukkan kalimat: ";
  cin.getline(kalimat, 100);

  //input hurf yang ingindicari
  cout << "Masukkan karakter yang ingin dicari: ";
  cin >> target;

  //menghitung panjang kalimat
  int n = strlen(kalimat); 

  binarySearch(kalimat, target, n);

  return 0;
}
```
#### Output:
![Screenshot 2024-05-22 233454](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/fc17ea73-56f7-421b-b220-2503a952df02)
Program ini mencari karakter dalam kalimat menggunakan algoritma binary search. Algoritma ini bekerja dengan cara membagi array karakter (kalimat) menjadi dua bagian secara berulang dan membandingkan nilai tengah dengan karakter yang dicari (target). Jika target ditemukan, indeksnya dikembalikan. Jika target tidak ditemukan, kode akan menampilkan pesan bahwa target tidak ada. Kode ini menggunakan fungsi binarySearch yang didefinisikan dengan parameter: array karakter (kalimat), karakter target, dan panjang array (n). Fungsi ini menggunakan loop while untuk membagi array dan membandingkan nilai tengah. Jika target ditemukan, indeksnya disimpan dalam variabel index dan loop dihentikan. Jika target tidak ditemukan, index akan tetap -1 dan pesan "Karakter tidak ditemukan" dicetak. Fungsi main bertanggung jawab untuk mendapatkan input dari pengguna (kalimat dan target), menghitung panjang kalimat (n), dan memanggil fungsi binarySearch untuk melakukan pencarian.

### 2. Buatlah sebuah program yang dapat menghitung banyaknya huruf vocal dalam sebuah kalimat!
```C++
//Irshad Benaya Fardeca
//2311102199

#include <iostream>

using namespace std;

int main() {

    //inisialisasi dan deklarasi
    string kalimat;
    int vokal = 0;

    //input kalimat
    cout << "Masukkan kalimat: ";
    getline(cin, kalimat);

    //sequential search
    for (int i = 0; i < kalimat.length(); i++) {
    char huruf = kalimat[i];

    if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u' || huruf == 'A' || huruf == 'E' || huruf == 'I' || huruf == 'O' || huruf == 'U') {
        vokal++;
        }
    }

    //output
    cout << "Jumlah huruf vokal yang terdapat dalam kalimat: " << vokal << endl;

return 0;
}

```
#### Output:
![Screenshot 2024-05-22 213736](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/028c9629-62ac-493a-b219-d322ae8e2710)
Program ini menunjukkan program untuk menghitung jumlah huruf vokal dalam sebuah kalimat. Program ini dimulai dengan mendefinisikan variabel untuk menyimpan kalimat dan variabel untuk menampung jumlah vokal. Kemudian, program meminta pengguna untuk memasukkan kalimat. Selanjutnya, program melakukan sequential search pada setiap karakter dalam kalimat. Jika karakter tersebut merupakan huruf vokal (a, e, i, o, u, A, E, I, O, U), maka variabel vokal diincrement. Akhirnya, program menampilkan jumlah vokal yang ditemukan dalam kalimat.

### 3. Diketahui data = 9, 4, 1, 4, 7, 10, 5, 4, 12, 4. Hitunglah berapa banyak angka 4 dengan menggunakan algoritma Sequential Search!

```C++
//Irshad Benaya Fardeca
//2311102199

#include <iostream>

using namespace std;

  //inisialisasi dan deklarasi
  int main() {
  int ukuran = 10;
  int data[ukuran] = {9, 4, 1, 4, 7, 10, 5, 4, 12, 4};
  int count = 0;

  //sequential search
  for (int i = 0; i < ukuran; i++) {
    if (data[i] == 4) {
      count++;
    }
  }

  //Mneampilkan data
  cout << "Data : ";
  for(int i; i<10; i++){
    cout << data[i] << " ";
  }
  cout << endl;

  //output
  cout << "Banyaknya angka 4 dalam data adalah: " << count << endl;

return 0;
}

```
#### Output:
![Screenshot 2024-05-22 213839](https://github.com/Cryoschr/Struktur-Data-Assigment/assets/161663646/4feafb04-a5e1-42c1-8098-ee971a063cfb)
Program ini menunjukkan program untuk menghitung jumlah kemunculan angka 4 dalam sebuah array. Program ini dimulai dengan mendefinisikan variabel untuk menyimpan ukuran array, array data itu sendiri, dan variabel untuk menampung jumlah angka 4. Selanjutnya, program menginisialisasi array data dengan 10 elemen. Kemudian, program melakukan pencarian sekuensial pada setiap elemen array. Jika elemen tersebut sama dengan 4, maka variabel count diincrement. Akhirnya, program menampilkan array data dan jumlah angka 4 yang ditemukan

## Kesimpulan
Sequential Search merupakan algoritma pencarian yang cocok untuk data tidak terurut. Algoritma ini bekerja dengan membandingkan setiap elemen array secara berurutan hingga data yang dicari ditemukan. Kelebihan Sequential Search adalah mudah diimplementasikan, namun kelemahannya adalah tidak efisien untuk data besar karena memerlukan banyak operasi perbandingan. Binary Search merupakan algoritma pencarian yang ideal untuk data yang sudah terurut. Algoritma ini bekerja dengan cara membagi array menjadi dua bagian secara berulang dan membandingkan nilai target dengan elemen di tengah. Keuntungan utama Binary Search adalah efisiensi dalam mencari data, terutama pada kumpulan data besar. Namun, perlu diingat bahwa Binary Search hanya dapat digunakan pada data yang sudah terurut. Membutuhkan proses sorting data terlebih dahulu sebelum menggunakan Binary Search.

## Referensi
[1] Darmawantoro, R. Y., Utami, Y. R. W., & Kustanto, K. (2022). Implementasi binary search untuk data obat di apotek. Jurnal Teknologi Informasi dan Komunikasi (TIKomSiN), 10(1), 76-84.
[2] Aminnur, M., Pakpahan, R. S., Alfarizi, D. G., Apriana, D., Rahmat, S. M., Fauzi, A., & Rosyani, P. (2023). IMPLEMENTASI METODE SEQUENTIAL SEARCH UNTUK PENGELOLAAN DATA BARANG PADA SISTEM APLIKASI SIKILAT CARGO. LOGIC: Jurnal Ilmu Komputer dan Pendidikan, 1(2), 283-287.
