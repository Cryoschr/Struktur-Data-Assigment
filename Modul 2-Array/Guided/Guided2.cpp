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