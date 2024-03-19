#include <iostream>
using namespace std;

int main(){
    int a,b,c;

    //Input panjang array
    cout<<"Masukkan Panjang Array 3 Dimensi: "<<endl;
    cout<<"[][][]\n";
    cin>>a;
    cout<<"[" <<a<< "][][]\n";
    cin>>b;
    cout<<"[" <<a<< "][" <<b<< "][]\n";
    cin>>c;
    //Menampilkan panjang array
    cout<<"Array[" <<a<< "][" <<b<< "][" <<c<< "]\n";
    cout<<endl;

    //Deklarasi array
    int array[a][b][c];
    //Input array
    cout<<"Masukkan Nilai Array : "<<endl;
    for (int x=0; x<a; x++){
        for (int y=0; y<b; y++){
            for (int z=0; z<c; z++){
                cout<<"Input Array[" << x << "][" << y << "][" << z << "] = ";
                cin>>array[x][y][z];
            }
            cout<<endl;
        }
        cout<<endl;
    }

    //Menampikan array
    cout<<"Tampilan Array 3 Dimensi : "<<endl;
    for (int x=0; x<a; x++){
        for (int y=0; y<b; y++){
            for (int z=0; z<c; z++){
                cout<<array[x][y][z]<<ends;
            }
            cout<<endl;
        }
        cout<<endl;
    }

    return 0;
}