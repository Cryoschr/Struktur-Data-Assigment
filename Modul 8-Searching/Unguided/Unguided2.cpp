//Irshad Benaya Fardeca
//2311102199

#include <iostream>

using namespace std;

int main() {
  string kalimat;
  int vokal = 0;

  cout << "Masukkan kalimat: ";
  getline(cin, kalimat);

  for (int i = 0; i < kalimat.length(); i++) {
    char huruf = kalimat[i];

    if (huruf == 'a' || huruf == 'e' || huruf == 'i' || huruf == 'o' || huruf == 'u' ||
        huruf == 'A' || huruf == 'E' || huruf == 'I' || huruf == 'O' || huruf == 'U') {
      vokal++;
    }
  }

  cout << "Jumlah huruf vokal yang terdapat dalam kalimat: " << vokal << endl;

  return 0;
}
