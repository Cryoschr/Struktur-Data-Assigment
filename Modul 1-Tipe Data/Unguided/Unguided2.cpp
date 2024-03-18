// #include <iostream>

// using namespace std;

// Deklarasi class
// class Murid {
//  public:
//    string nama;
//    int usia;
//    int nim;

// Prosedur untuk mencetak nilai variabel
//    void cetak() {
//      cout << "Nama: " << nama << endl;
//      cout << "Usia: " << usia << endl;
//      cout << "NIM: " << nim << endl;
//    }
// };

// int main() {

// Membuat objek baru
//   Murid murid;
//   murid.nama = "Irshad";
//   murid.usia = 18;
//   murid.nim = 199;

// Pemanggilan prosedur
//   murid.cetak();

//   return 0;
// }



#include <iostream>

using namespace std;

//Mendeklarasi struct
struct motor {
  string merek;
  string jenis;
};

int main() {

//Membuat objek baru
  motor motor;
  motor.merek = "Honda";
  motor.jenis = "Beat";

//Mencetak nilai varibel
  cout << "Merek Motor: " << motor.merek << endl;
  cout << "Jenis Motor: " << motor.jenis << endl;

  return 0;
}
