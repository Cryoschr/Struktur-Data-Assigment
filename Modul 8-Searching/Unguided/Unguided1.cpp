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
