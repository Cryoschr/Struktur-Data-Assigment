//Irshad Benaya Fardeca
//2311102199

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

//inisialisasi dan deklarasi
string arrayKata [15];
int maks = 15, top = 0;

//cek apakah penuh
bool isFull(){
    return (top == maks);
}

//mengubah huruf besar menjadi kecil
string lowerCase(string kataLower){

    string lowercase= "";

    for (int i = 0; i <kataLower.length(); i++) {
        lowercase += tolower(kataLower[i]);
    }
    return lowercase;
}

// Periksa apakah kalimatnya palindrom
void palindrom(string kataLower){

    string kata = lowerCase(kataLower);
    string palindromKata = "";

    for (int i = kataLower.length() - 1; i >= 0; i--){
        palindromKata += kata[i];
    }


    if (kata == palindromKata) {
        cout << "Kata tersebut adalah Palindrom" << endl;
    } else {
        cout << "Kata tersebut adalah Bukan Palindrom" << endl;
    }
}

//memasukkan data
void pushKata(string data){
    if (isFull()){
        cout<<"Data penuh"<<endl;
    }else{
        palindrom(data);
        arrayKata[top]=data;
        top++;
    }
}

int main(){
    // Masukkan kata
    string kata;
    cout << "Masukkan kata: ";
    getline(cin, kata);
    pushKata(kata);


return 0;
}