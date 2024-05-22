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
