#include <iostream>

using namespace std;




void binarySearch(string kalimat[], char huruf, int target){
    int awal=0, akhir=huruf-1, tengah, index=0;

    while(index == 0 && awal <= akhir){
        tengah = (awal + akhir)/2;
        if(kalimat[tengah] == target){
            index = 1;
            break;
        }else if(kalimat[tengah] < target){
            awal = tengah + 1;
        }else{
            akhir = tengah -1;
        }
    }

    if(index == 1 ){
        cout << "Data ditemukan " << tengah << endl;
    }else{
        cout << "Data tidak ditemukan";
    }

}

int main(){

string kalimat;
char cari;

    cout << "Masukkkan kalimat: ";
    getline(cin, kalimat);

    cout << "Huruf yang ingin dicari: ";
    cin >> cari;



    binarySearch(kalimat, 100, cari);
    return 0;
}