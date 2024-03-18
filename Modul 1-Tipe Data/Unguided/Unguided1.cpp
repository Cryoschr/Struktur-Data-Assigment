#include <iostream>

using namespace std;

//fungsi luas lingkaran
float luas(int r){
    return 3.14*r*r;
}

//fungsi keliling lingkaran
float keliling(int r){
    return 2*3.14*r;
}

int main(){
    int r;

//Menginputkan jari-jari
    cout<<"Menghitung luas dan keliling lingkaran"<<endl;
    cout<<"Input panjang jari-jari lingkaran: ";
    cin>>r;

//Mencetak hasil
    cout<<"Luas lingkaran: ";
    cout<<luas(r)<<endl;
    cout<<"Keliling Lingkaran: ";
    cout<<keliling(r);

    return 0;
}