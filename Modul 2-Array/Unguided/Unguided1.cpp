#include <iostream>
using namespace std;

int main(){
    //Deklarasi variabel
    int genap;
    //Deklarasi array
    int array[10]={1,2,3,4,5,6,7,8,9,10};

    //Menampilkkan array
    cout<<"Data Array   :";
    for (int i=0; i<10; i++){
        cout << " "<<array[i];
    }
    cout<<endl;

    //Mencari array dengan nomor genap
    cout<<"Nomor Genap  :";
    for (int i=0; i<10; i++){
        if(array[i] % 2 == 0){
            cout<<" "<<array[i];
        }
    }
    cout<<endl;
    
    //Mencari array dengan nomor ganjil
    cout<<"Nomor Ganjil :";
    for (int i=0; i<10; i++){
        if(array[i] % 2 != 0){
            cout<<" "<<array[i];
        }
    }
    return 0;
}