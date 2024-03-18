#include <iostream>
#include <map>

using namespace std;

int main() {
  // Membuat map kosong
  map<string, int> u;

  // Menambahkan elemen ke map
  u["Budi"] = 20;
  u["Ani"]  = 21;
  u["Cici"] = 22;

  // Menampilkan isi map
  for (auto it = u.begin(); it != u.end(); ++it) {
    cout << "Umur " << it->first << " : " << it->second << endl;
  }

  return 0;
}
