#include <iostream>
using namespace std;

int main(){
    //Deklarasi variabel
    int menu,a,maks,min,i=1;
    float rata,total;

    //Input panjang array
    cout<<"Masukkan Panjang Array : ";
    cin>>a;

    //Deklarasi array
    int array[a];
 
    //Input array
    for (i=0; i<a; i++){
        cout<<"Array index ke-"<<i<<" = ";
        cin>>array[i];
    }
    cout<<endl;

    //Tampilan menu
    cout<<"     Menu\n";
    cout<<"1. Nilai Maksimum\n";
    cout<<"2. Nilai Minimum\n";
    cout<<"3. Nilai Rata-Rata\n";
    cout<<"Pilih Nomor : ";
    cin>>menu;


    switch (menu){
    case 1:
    //Mencari nilai maksimum array
        maks=array[0];
        for (i=0; i<a; i++){
            if(array[i]>maks){
                maks=array[i];
            }
        }
        cout<<"Nilai Maksimum = "<<maks;
    cout<<endl;
        break;

    case 2:
    //Mencari nilai minimum array
        min=array[0];
        for (i=0; i<a; i++){
            if(array[i]<min){
                min=array[i];
            }
        }
        cout<<"Nilai Minimum = "<<min;
    cout<<endl;
        break;

    case 3:
    //Mencari rata-rata array
        for (i=0; i<a; i++){
            total+=array[i];
        }
        rata=total/a;
        cout<<"Rata-Rata = "<<rata;
        cout<<endl;
        break;

    default:
        cout<<"Silahkan Coba Lagi :]";
    cout<<endl;
        break;
    }
    return 0;
}